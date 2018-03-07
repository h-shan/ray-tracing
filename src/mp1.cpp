#include <iostream>
#include <float.h>
#include <cmath>

#include "pngutil/PNG.h"
#include "vec3.h"
#include "ray.h"
#include "camera.h"
#include "hitable.h"
#include "sphere.h"
#include "triangle.h"
#include "hitable_list.h"
#include "random.h"
#include "lambertian.h"

vec3 color(const ray &r, hitable *world, double depth) {
  hit_record rec;
  if (world->hit(r, 0.0, DBL_MAX, rec)) {
    ray scattered;
    vec3 attenuation;
    if (depth < 50 && rec.mat->scatter(r, rec, attenuation, scattered)) {
      return attenuation * color(scattered, world, depth+1);
    } else {
      return vec3();
    }
  } else {
    vec3 unit_direction = r.direction().unit_vector();
    double t = (unit_direction.y() + 1.0) * 0.5;
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) * (1.0 - t) + vec3(0.5, 0.7, 1.0) * t;
  }
}

int main() {
  srand (time(NULL));
  unsigned width = 200;
  unsigned height = 100;
  
  pngutil::PNG img(width, height);

  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, 0.0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0, 0.0, 0.0);
  hitable *list[3];
  list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
  list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
  list[2] = new triangle(vec3(-1, 0, -1), vec3(-1, 1, -1), vec3(-1.5, -1, -2), new lambertian(vec3(0.5, 0.5, 1)));
  hitable *world = new hitable_list(list, 3);

  camera cam;
  for (unsigned i = 0; i < width; i++) {
    for (unsigned j = 0; j < height; j++) {
      double u = double(i) / double(width);
      double v = double(height - 1 - j) / double(height);
      vec3 col;
      for (unsigned k = 0; k < 100; k++) {
        ray r = cam.get_ray(u + rand_double() / width, v + rand_double() / height); 
        col += color(r, world, 0);
      }
      col /= 100;
      col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
      *img.getPixel(i, j) = pngutil::RGBAPixel(int(255.99 * col[0]), int(255.99 * col[1]), int(255.99 * col[2]));
    }
  }

  if (img.writeToFile("test.png")) {
    cout << "Output saved to test.png" << endl;  
  } else {
    cout << "Could not write image" << endl; 
  }
  delete world;
  return 0;
}

