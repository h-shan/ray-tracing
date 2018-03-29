#include <cmath>
#include "triangle.h"

triangle::triangle(vec3 a, vec3 b, vec3 c, material *mat) :
  a_{a},
  b_{b},
  c_{c},
  mat_{mat}
{
  normal_ = (b-a).cross(c-a);
}

// code from https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/barycentric-coordinates
bool triangle::hit(const ray &r, double t_min, double t_max, hit_record &rec) const 
{
  double denom = r.direction().dot(normal_);
  if (fabs(denom) < epsilon) {
    return false;
  }
  vec3 normal = normal_;
  if (denom > 0) {
    normal = -normal;
    denom = -denom;
  }
  double t = (a_ - r.origin()).dot(normal) / denom;
  if (t <= t_min || t >= t_max) {
    return false;
  }
  // std::cout << t << std::endl;
  vec3 p = r.origin() + r.direction() * t;
  vec3 c;
 
  if ((p-a_).dot(normal_) > 10e-5) {
    std::cout << "Big error" << std::endl;
    return false;
  }
  
  // edge 0
  vec3 edge_0 = b_ - a_;
  vec3 vp_0 = p - a_;
  c = edge_0.cross(vp_0);
  if (normal.dot(c) < 0) {
    // std::cout << "edge 0: " << normal.dot(c) << " " << std::endl;
    return false;
  }
  
  // edge 1
  vec3 edge_1 = c_ - b_;
  vec3 vp_1 = p - b_;
  c = edge_1.cross(vp_1);
  if (normal.dot(c) < 0) {
    // std::cout << "edge 1: " << normal.dot(c) << std::endl;
    return false;
  }

  // edge 2
  vec3 edge_2 = a_ - c_;
  vec3 vp_2 = p - c_;
  c = edge_2.cross(vp_2);
  if (normal.dot(c) < 0) {
    // std::cout << "edge 2: " << normal.dot(c) << std::endl;
    return false;
  }
  
  rec.t = t;
  rec.p = p;
  rec.normal = normal;
  if (denom > 0) {
    rec.normal = -normal;
  }
  rec.mat = mat_;

  return true;
}

bool triangle::bounding_box(double t0, double t1, aabb &box) const {
  return true;
}

