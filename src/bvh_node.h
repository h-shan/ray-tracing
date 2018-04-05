#ifndef BVHNODE_H
#define BVHNODE_H

#include "aabb.h"
#include "hitable.h"

class bvh_node : public hitable {
  public:
    bvh_node() {}
    bvh_node(hitable **l, int n, double time0, double time1);
    virtual bool bounding_box(double t0, double t1, aabb &box) const;
    virtual bool hit(const ray &r, double t0, double tmax, hit_record &rec) const; 
    
    hitable *left;
    hitable *right;
    aabb box;
    
};

#endif
