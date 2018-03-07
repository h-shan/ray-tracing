#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"
#include "material.h"

class material;

struct hit_record {
  double t;
  vec3 p;
  vec3 normal;
  const material *mat;
  hit_record() : t{-1} {}
};

class hitable {
  public:
    virtual ~hitable() {}
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif
