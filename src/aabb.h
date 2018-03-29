#ifndef AABB_H
#define AABB_H

#include "ray.h"

class aabb {
  public:
    aabb() {}
    aabb(const vec3 &a, const vec3 &b);

    vec3 min() const;
    vec3 max() const;
    bool hit(const ray &r, double tmin, double tmax) const;

  private:
    vec3 _min;
    vec3 _max;
};

#endif
