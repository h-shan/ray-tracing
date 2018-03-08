#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class camera {
  public:
    virtual ray get_ray(double u, double v) const = 0;
};



#endif
