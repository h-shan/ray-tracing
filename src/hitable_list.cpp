#include "hitable.h"
#include "hitable_list.h"

hitable_list::hitable_list() :  
  list_size{0}
{}

hitable_list::hitable_list(hitable **list, unsigned n) :
  list{list},
  list_size{n}
{}

bool hitable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
  hit_record temp_rec;
  bool hit_target = false;
  double closest = t_max;
  for (unsigned i = 0; i < list_size; i++) {
    if (list[i]->hit(r, t_min, closest, temp_rec)) {
      hit_target = true;
      closest = temp_rec.t;
      rec = temp_rec;
    }
  }
  return hit_target;
}
