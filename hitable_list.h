#ifndef HITABLE_LIST_H
#define HITABLE_LIST_H

#include "hitable.h"

class hitable_list : public hitable {
  public:
    hitable_list();
    hitable_list(hitable **list, unsigned n);
    virtual ~hitable_list() {}
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
    hitable **list;
    unsigned list_size;
};

#endif
