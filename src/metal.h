#ifndef METAL_H
#define METAL_H

#include "material.h"

class metal : public material {
  public:
    metal(const vec3 &albedo);
    virtual bool scatter(const ray &r_in, const struct hit_record &rec, vec3 &attenuation, ray &scattered) const;
  
  private:
    vec3 albedo_;
    vec3 _reflect(const vec3 &v, const vec3 &n) const;
};


#endif
