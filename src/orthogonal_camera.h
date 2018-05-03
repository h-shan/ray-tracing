#ifndef ORTHOGONAL_CAMERA_H
#define ORTHOGONAL_CAMERA_H

class orthogonal_camera {
  public:
    orthogonal_camera(double z = 1);
    ray get_ray(double u, double v) const;
  private:
    double z_;
};

#endif
