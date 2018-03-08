#ifndef LIGHT_H
#define LIGHT_H

#include "vec3.h"

class light {
  public:
    light(const vec3 &direction, double intensity);
    virtual ~light() {}
    vec3 direction;
    vec3 color; 
    double intensity;
};

#endif
