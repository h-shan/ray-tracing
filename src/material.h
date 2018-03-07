#ifndef MATERIAL_H
#define MATERIAL_H

#include "hitable.h"
#include "ray.h"

class material {
  public:
    virtual bool scatter(const ray &r_in, const struct hit_record &rec, vec3 &attenuation, ray &scattered) const = 0;
};

#endif
