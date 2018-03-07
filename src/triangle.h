#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hitable.h"

class triangle : public hitable {
  public:
    triangle(vec3 a, vec3 b, vec3 c);
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
  private:
    vec3 a_;
    vec3 b_;
    vec3 c_;
    vec3 normal_;
    double area_;
    static constexpr const double epsilon = 1.0e-8;
};

#endif
