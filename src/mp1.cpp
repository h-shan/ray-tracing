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
#include "plane.h"
#include "hitable_list.h"
#include "random.h"
#include "lambertian.h"
#include "metal.h"
#include "light.h"

vec3 color(const ray &r, hitable *world) {
  // light from back left
  light dir_light(vec3(1, -1 , -1), 1);

  vec3 ambient_color = vec3(0.05, 0.05, 0.05);
  hit_record rec;
  if (world->hit(r, 0.01, 5, rec)) {
   // cout << rec.t << endl;
    ray scattered;
    vec3 albedo;
    rec.mat->scatter(r, rec, albedo, scattered);
    vec3 light_dir = -dir_light.direction;
    vec3 col;
    vec3 diffuse_color;
    if (light_dir.dot(rec.normal) > 0) {
      diffuse_color = light_dir.dot(rec.normal) * dir_light.intensity * dir_light.color * albedo / M_PI;
      hit_record temp;
      bool visible = !world->hit(ray(rec.p, light_dir), 0.01, DBL_MAX, temp);
      diffuse_color *= visible;
    }
    col = albedo * ambient_color + diffuse_color;
    return col;
  } else {
    return vec3();
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
  hitable *list[5];
  list[0] = new plane(vec3(0, 0.8, -1), vec3(0, -1, -0.2), new lambertian(vec3(1, 0, 0))); 
  list[1] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
  list[2] = new sphere(vec3(1, -0.5, -1), 0.5, new lambertian(vec3(0.3, 0.8, 0.3)));
  list[3] = new triangle(vec3(-1, 0, -0.5), vec3(0, 1, -1), vec3(0.5, 0, -0.5), new lambertian(vec3(0, 0, 1)));

 hitable *world = new hitable_list(list, 4);

  camera cam;
  for (unsigned j = 0; j < height; j++) {
    for (unsigned i = 0; i < width; i++) {
      double u = double(i) / double(width);
      double v = double(height - 1 - j) / double(height);
      vec3 col;
      for (unsigned k = 0; k < 100; k++) {
        ray r = cam.get_ray(u + rand_double() / width, v + rand_double() / height); 
        col += color(r, world);
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

