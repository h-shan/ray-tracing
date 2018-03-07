#include <cmath>
#include "triangle.h"

triangle::triangle(vec3 a, vec3 b, vec3 c) :
  a_{a},
  b_{b},
  c_{c}
{
  normal_ = (b-a).cross(c-a);
  area_ = normal_.length()/2;
}

// code from https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/barycentric-coordinates
bool triangle::hit(const ray &r, double t_min, double t_max, hit_record &rec) const 
{
  double normal_mag = r.direction().dot(normal_);
  if (fabs(normal_mag) < epsilon) {
    return false;
  }
  double d = normal_.dot(a_);
  double t = (normal_.dot(r.origin()) + d) / normal_mag;

  if (t <= t_min || t >= t_max) {
    return false;
  }
  vec3 p = r.origin() + r.direction() * t;

  vec3 c;
  
  // edge 0
  vec3 edge_0 = b_ - a_;
  vec3 vp_0 = p - a_;
  c = edge_0.cross(vp_0);
  if (normal_.dot(c) < 0) {
    return false;
  }
  
  // edge 1
  vec3 edge_1 = c_ - b_;
  vec3 vp_1 = p - b_;
  c = edge_1.cross(vp_1);
  if (normal_.dot(c) < 0) {
    return false;
  }

  // edge 2
  vec3 edge_2 = a_ - c_;
  vec3 vp_2 = p - c_;
  c = edge_2.cross(vp_2);
  if (normal_.dot(c) < 0) {
    return false;
  }
  
  rec.t = t;
  rec.p = p;
  rec.normal = normal_;
  
  return true;
}

