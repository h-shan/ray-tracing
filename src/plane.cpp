#include "plane.h"
#include <cmath>

plane::plane(vec3 point, vec3 normal, material *mat) :
  point_{point},
  mat_{mat}
{ 
  normal_ = normal.unit_vector();
}

bool plane::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
  double denom = r.direction().dot(normal_);
  // std::cout << denom << std::endl;
  // std::cout << r.direction() << std::endl;
  if (denom < epsilon) {
    return false;
  }
  vec3 normal = normal_;
  if (denom > 0) {
    normal = -normal_;
  }
  double t = (point_ - r.origin()).dot(normal) / denom;
  if (t <= t_min || t >= t_max) {
    return false;
  }
  rec.t = t;
  rec.p = r.origin() + r.direction() * t;
  rec.mat = mat_;
  rec.normal = normal;
  return true;
}

