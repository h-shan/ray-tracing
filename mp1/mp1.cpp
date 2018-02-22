#include "../pngutil/PNG.h"
#include "../pngutil/RGBAPixel.h"
#include "../vec3.h"
#include "../ray.h"
#include <iostream>


double hit_sphere(const vec3 &center, float radius, const ray &r) {
  vec3 oc = r.origin() - center;
  double a = r.direction().dot(r.direction());
  double b = 2 * r.direction().dot(oc);
  double c = oc.dot(oc) - radius * radius;
  double discriminant  = b*b - 4*a*c;
  if (discriminant < 0) {
    return -1.0;
  }
  return (-b - sqrt(discriminant)) / 2 * a;
}

vec3 color(const ray& r) {
  double t = hit_sphere(vec3(0, 0, -1), 0.5, r); 
  if (t > 0) {
    vec3 N = (r.point_at_parameter(t) - vec3(0, 0, -1)).unit_vector();
    return vec3(1, 0, 0);
  }
  vec3 unit_direction = r.direction().unit_vector();
  t = (unit_direction.y() + 1.0) * 0.5;
  return vec3(1.0, 1.0, 1.0) * (1.0 - t) + vec3(0.5, 0.7, 1.0) * t;
}

int main() {
  unsigned width = 200;
  unsigned height = 100;
  
  pngutil::PNG img(width, height);

  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, 0.0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0, 0.0, 0.0);

  for (unsigned i = 0; i < width; i++) {
    for (unsigned j = 0; j < height; j++) {
      double u = double(i) / double(width);
      double v = double(j) / double(height);
      ray r(origin, lower_left_corner + horizontal*u + vertical*v);
      vec3 col = color(r);
      *img.getPixel(i, j) = pngutil::RGBAPixel(int(255.99 * col[0]), int(255.99 * col[1]), int(255.99 * col[2]));
    }
  }

  if (img.writeToFile("test.png")) {
    cout << "Output saved to test.png" << endl;  
  } else {
    cout << "Could not write image" << endl; 
  }
  return 0;
}

