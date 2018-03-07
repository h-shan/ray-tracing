#include "metal.h"

metal::metal(const vec3 &albedo) :
  albedo_{albedo}
{}

bool metal::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
  vec3 reflected = _reflect(r_in.direction().unit_vector(), rec.normal);
  scattered = ray(rec.p, reflected);
  attenuation = albedo_;
  return scattered.direction().dot(rec.normal) > 0;
}

vec3 metal::_reflect(const vec3 &v, const vec3 &n) const {
  return v - 2 * v.dot(n) * n;
}
