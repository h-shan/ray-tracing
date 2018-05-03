#include <cmath>
#include "triangle.h"

triangle::triangle(vec3 a, vec3 b, vec3 c, material *mat) :
  a_{a},
  b_{b},
  c_{c},
  mat_{mat}
{
  normal_ = (b-a).cross(c-a);
  double minx = fmin(fmin(a.x(), b.x()), c.x());
  double miny = fmin(fmin(a.y(), b.y()), c.y());
  double minz = fmin(fmin(a.z(), b.z()), c.z());
  double maxx = fmax(fmax(a.x(), b.x()), c.x());
  double maxy = fmax(fmax(a.y(), b.y()), c.y());
  double maxz = fmax(fmax(a.z(), b.z()), c.z());
  b_box_ = aabb(vec3(minx, miny, minz), vec3(maxx, maxy, maxz));
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
  double d = -a_.dot(normal);
  double t = -(r.origin().dot(normal) + d) / denom;
  if (t <= t_min || t >= t_max) {
    return false;
  }
  vec3 p = r.origin() + r.direction() * t;
  vec3 c;

  if ((p-a_).dot(normal_) > 10e-5) {
    std::cout << "Big error" << std::endl;
    return false;
  }

  bool b0, b1, b2;
  // edge 0
  vec3 edge_0 = b_ - a_;
  vec3 vp_0 = p - a_;
  c = edge_0.cross(vp_0);

  if (normal.dot(c) > 0) {
    // std::cout << "edge 0: " << normal.dot(c) << " " << std::endl;
    // return false;
  }
  b0 = normal.dot(c) > 0;

  // edge 1
  vec3 edge_1 = c_ - b_;
  vec3 vp_1 = p - b_;
  c = edge_1.cross(vp_1);
  if (normal.dot(c) > 0) {
    // std::cout << "edge 1: " << normal.dot(c) << std::endl;
    // return false;
  }

  b1 = normal.dot(c) > 0;
  // edge 2
  vec3 edge_2 = a_ - c_;
  vec3 vp_2 = p - c_;
  c = edge_2.cross(vp_2);
  if (normal.dot(c) > 0) {
    // std::cout << "edge 2: " << normal.dot(c) << std::endl;
    // return false;
  }

  b2 = normal.dot(c) > 0;
  rec.t = t;
  rec.p = p;
  rec.normal = normal;
  if (denom > 0) {
    rec.normal = -normal;
  }
  rec.mat = mat_;

  return (b0 && b1 && b2) || (!b0 && !b1 && !b2);
}

bool triangle::bounding_box(double t0, double t1, aabb &box) const {
  box = b_box_;
  return true;
}
