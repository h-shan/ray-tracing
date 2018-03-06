#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"
#include "vec3.h"
#include "ray.h"

class sphere: public hitable {
  public:
    sphere();
    sphere(vec3 cen, double radius);
    virtual bool hit(const ray &radius, double t_min, double t_max, hit_record &rec) const;

  private:
    double radius_;
    vec3 center_;
};

#endif
