#include "ray.h"
#include "orthogonal_camera.h"

orthogonal_camera::orthogonal_camera(double z) :
  z_{z}
{}

ray orthogonal_camera::get_ray(double u, double v) const {
  return ray(vec3(u, v, z_), vec3(0, 0, -1));
}
