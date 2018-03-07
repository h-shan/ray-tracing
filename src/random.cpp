#include "random.h"

double rand_double() {
  double d = rand();
  if (d == RAND_MAX) {
    d -= 1;
  }
  return d / RAND_MAX;
}

vec3 random_in_unit_sphere() {
  vec3 p;
  do {
    p = 2.0 * vec3(rand_double(), rand_double(), rand_double()) - vec3(1, 1, 1);
  } while (p.dot(p) > 1);
  return p;
}
