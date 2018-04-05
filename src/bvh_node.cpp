#include <stdlib.h>
#include <math.h>

#include "bvh_node.h"
#include "random.h"

bool bvh_node::bounding_box(double t0, double t1, aabb &b) const {
  b = box;
  return true;
}

int box_x_compare(const void * a, const void * b) {
  aabb box_left, box_right;
  hitable *ah = *(hitable**)a;
  hitable *bh = *(hitable**)b;
  if (!ah->bounding_box(0,0, box_left) || !bh->bounding_box(0,0, box_right)) {
    std::cerr << "no bounding box in bvh_node constructor\n";
  }
  if (box_left.min().x() - box_right.min().x() < 0) {
    return -1;
  } else {
    return 1;
  }
}

int box_y_compare(const void * a, const void * b) {
  aabb box_left, box_right;
  hitable *ah = *(hitable**)a;
  hitable *bh = *(hitable**)b;
  if (!ah->bounding_box(0,0, box_left) || !bh->bounding_box(0,0, box_right)) {
    std::cerr << "no bounding box in bvh_node constructor\n";
  }
  if (box_left.min().x() - box_right.min().x() < 0) {
    return -1;
  } else {
    return 1;
  }
}

int box_z_compare(const void * a, const void * b) {
  aabb box_left, box_right;
  hitable *ah = *(hitable**)a;
  hitable *bh = *(hitable**)b;
  if (!ah->bounding_box(0,0, box_left) || !bh->bounding_box(0,0, box_right)) {
    std::cerr << "no bounding box in bvh_node constructor\n";
  }
  if (box_left.min().x() - box_right.min().x() < 0) {
    return -1;
  } else {
    return 1;
  }
}

aabb surrounding_box(aabb box0, aabb box1) {
  vec3 small(fmin(box0.min().x(), box1.min().x()),
      fmin(box0.min().x(), box1.min().x()),
      fmin(box0.min().z(), box1.min().z()));
  vec3 big(fmax(box0.max().x(), box1.max().x()),
      fmax(box0.max().x(), box1.max().x()),
      fmax(box0.max().z(), box1.max().z()));
  return aabb(small, big);
}

bool bvh_node::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
  if (box.hit(r, t_min, t_max)) {
    hit_record left_rec, right_rec;
    bool hit_left = left->hit(r, t_min, t_max, left_rec);
    bool hit_right = right->hit(r, t_min, t_max, right_rec);
    if (hit_left && hit_right) {
      rec = left_rec.t < right_rec.t ? left_rec : right_rec;
      return true;
    } else if (hit_left) {
      rec = left_rec;
      return true;
    } else if (hit_right) {
      rec = right_rec;
      return true;
    } else {
      return false;
    }
  }
  return false;
}

bvh_node::bvh_node(hitable **l, int n, double t0, double t1) {
  int axis = int(3 * rand_double());
  switch(axis) {
    case 0:
      qsort(l, n, sizeof(hitable *), box_x_compare);
      break;
    case 1:
      qsort(l, n, sizeof(hitable *), box_y_compare);
      break;
    default:
      qsort(l, n, sizeof(hitable *), box_z_compare);
      break;
  }
  switch(n) {
    case 1:
      left = right = l[0];;
      break;
    case 2:
      left = l[0];
      right = l[1];
      break;
    default:
      left = new bvh_node(l, n/2, t0, t1);
      right = new bvh_node(l + n/2, n-n/2, t0, t1);
  }
  aabb box_left, box_right;
  if (!left->bounding_box(t0, t1, box_left) || !right->bounding_box(t0, t1, box_right)) {
    std::cerr << "No bounding box in bvh+node constructor\n";
  }
  box = surrounding_box(box_left, box_right);
}
