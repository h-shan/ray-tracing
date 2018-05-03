#include "light.h"

light::light(const vec3 &dir, double intensity) :
  color{vec3(1, 1, 1)},
  intensity{intensity}
{
  direction = dir;
  direction.make_unit_vector();
}
