#include "../pngutil/PNG.h"
#include "../pngutil/RGBAPixel.h"
#include "../vec3.h"
#include "../ray.h"
#include <iostream>

vec3 color(const ray& r) {
  vec3 unit_direction = r.direction().unit_vector();
  double t = (unit_direction.y() + 1.0) * 0.5;
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
