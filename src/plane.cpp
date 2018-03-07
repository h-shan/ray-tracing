#include "plane.h"

plane::plane(vec3 point, vec3 normal, material *mat) :
  point_{point},
  mat_{mat}
{ 
  normal_ = normal.unit_vector();
}

bool plane::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
  double denom = r.direction().dot(normal_);
  if (denom < epsilon) {
    return false;
  }
  double t = (point_ - r.origin()).dot(normal_) / denom;
  if (t <= t_min || t >= t_max) {
    return false;
  }
  rec.t = t;
  rec.p = r.origin() + r.direction() * t;
  rec.normal = normal_;
  rec.mat = mat_;
  return true;
}

