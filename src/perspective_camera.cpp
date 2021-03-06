
#include "ray.h"
#include "perspective_camera.h"

perspective_camera::perspective_camera() {
  origin = vec3(0, 0, 0);
  vertical = vec3(0, 2, 0);
  horizontal = vec3(4, 0, 0);
  lower_left_corner = vec3(-2, -1, -1);
}

ray perspective_camera::get_ray(double u, double v) const {
  return ray(origin, (lower_left_corner + u*horizontal + v*vertical - origin).unit_vector());
}
