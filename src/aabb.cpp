#include "aabb.h"

double dmin(double a, double b) 
{
  return a < b ? a : b;
}

double dmax(double a, double b)
{
  return a > b ? a : b;
}

aabb::aabb(const vec3 &a, const vec3 &b) : 
  _min{a},
  _max{b}
{}

vec3 aabb::min() const
{
  return _min;
}

vec3 aabb::max() const
{
  return _max;
}

bool aabb::hit(const ray &r, double tmin, double tmax) const
{
  for (unsigned i = 0; i < 3; i++) {
    double amin = (_min[i] - r.origin()[i]) / r.direction()[i]; 
    double amax = (_max[i] - r.origin()[i]) / r.direction()[i]; 
  
    double t0 = dmin(amin, amax);
    double t1 = dmax(amin, amax);
    tmin = dmax(t0, tmin);
    tmax = dmin(t1, tmax);
    if (tmax <= tmin) {
      return false;
    }
  }
  return true;
}

