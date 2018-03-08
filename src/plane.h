#ifndef PLANE_H
#define PLANE_H

#include "hitable.h"

class plane : public hitable {
  public:
    plane(vec3 point, vec3 normal, material *mat);
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
  
  private:
    vec3 point_;
    vec3 normal_;
    material *mat_;
    static constexpr double epsilon = 10e-6;
};


#endif
