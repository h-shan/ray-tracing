#include <cmath>
#include "sphere.h"

sphere::sphere() :
  radius_{1}
{}

sphere::sphere(vec3 cen, double radius, material *mat) :
  radius_{radius},
  center_{cen},
  mat_{mat}
{}

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
  vec3 oc = r.origin() - center_;
  double a = r.direction().dot(r.direction());
  double b = 2 * r.direction().dot(oc);
  double c = oc.dot(oc) - radius_ * radius_;
  double disc = b*b - 4*a*c;

  if (disc > 0) {
    double time = (-b - sqrt(disc)) / (2*a);
    if (time > t_min && time < t_max) {
      rec.mat = mat_;
      rec.t = time;
      rec.p = r.point_at_parameter(time);
      rec.normal = (rec.p - center_).unit_vector();
      return true;
    }

    time = (-b + sqrt(disc)) / (2*a);
    if (time > t_min && time < t_max) {
      rec.mat = mat_;
      rec.t = time;
      rec.p = r.point_at_parameter(time);
      rec.normal = (rec.p - center_).unit_vector();
      return true;
    }
  }
  return false;
}

bool sphere::bounding_box(double t0, double t1, aabb &box) const {
  box = aabb(center_ - vec3(radius_, radius_, radius_), center_ + vec3(radius_, radius_, radius_));
  return true;
}

