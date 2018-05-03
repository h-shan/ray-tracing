#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hitable.h"
#include "material.h"

class triangle : public hitable {
  public:
    triangle(vec3 a, vec3 b, vec3 c, material *mat);
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
    virtual bool bounding_box(double t0, double t1, aabb &box) const;
  private:
    vec3 a_;
    vec3 b_;
    vec3 c_;
    vec3 normal_;
    material *mat_;
    aabb b_box_;
    static constexpr const double epsilon = 1.0e-8;
};

#endif
