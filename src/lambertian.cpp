#include "lambertian.h"
#include "random.h"

lambertian::lambertian(const vec3 &albedo) :
  albedo_{albedo}
{}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, vec3 &albedo, ray &scattered) const {
  vec3 target = rec.p + rec.normal + random_in_unit_sphere();
  scattered = ray(rec.p, target-rec.p);
  albedo = albedo_;
  return true;
}
