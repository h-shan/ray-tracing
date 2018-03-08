#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include "camera.h"

class perspective_camera : public camera {
  public:
    perspective_camera();
    ray get_ray(double u, double v) const;
  private:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};


#endif
