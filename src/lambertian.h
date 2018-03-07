#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"

class lambertian : public material {
  public:
    lambertian(const vec3 &vec);
    virtual bool scatter(const ray &r_in, const struct hit_record &rec, vec3 &attenuation, ray &scattered) const;
  
  private:
    vec3 albedo;
};

#endif

