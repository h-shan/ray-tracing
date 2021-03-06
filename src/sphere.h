#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"
#include "material.h"

class sphere: public hitable {
  public:
    sphere();
    sphere(vec3 cen, double radius, material *mat);
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
    virtual bool bounding_box(double t0, double t1, aabb &box) const;

  private:
    double radius_;
    vec3 center_;
    material *mat_;
};

#endif
