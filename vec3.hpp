// code based on Peter Shirley's book "Ray Tracing in One Weekend"
#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
  public:
    vec3() { e[0] = 0; e[1] = 0; e[2] = 2;};
    vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; };
    inline double x() const { return e[0]; }
    inline double y()const { return e[1]; }
    inline double z() const { return e[2]; }
    inline double r() const { return e[0]; }
    inline double g() const { return e[1]; }
    inline double b() const { return e[2]; }

    inline const vec3 & operator+() const { return *this; }
    inline const vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    inline double operator[](int i) const { return e[i]; }
    inline double& operator[](int i) { return e[i]; }
    
    inline vec3& operator+=(const vec3 &v2) { for (unsigned i = 0; i < 3; i++) e[i] += v2.e[i]; return *this; }
    inline vec3& operator-=(const vec3 &v2) { for (unsigned i = 0; i < 3; i++) e[i] -= v2.e[i]; return *this; }
    inline vec3& operator*=(const vec3 &v2) { for (unsigned i = 0; i < 3; i++) e[i] *= v2.e[i]; return *this; }
    inline vec3& operator/=(const vec3 &v2) { for (unsigned i = 0; i < 3; i++) e[i] /= v2.e[i]; return *this; }
    inline vec3& operator+=(const double d) { for (unsigned i = 0; i < 3; i++) e[i] += d; return *this; } 
    inline vec3& operator-=(const double d) { for (unsigned i = 0; i < 3; i++) e[i] -= d; return *this; }
    inline vec3& operator*=(const double d) { for (unsigned i = 0; i < 3; i++) e[i] *= d; return *this; }
    inline vec3& operator/=(const double d) { for (unsigned i = 0; i < 3; i++) e[i] /= d; return *this; }

    inline double length() const { return sqrt(squared_length()); }
    inline double squared_length() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
    inline void make_unit_vector() { 
      const double len = length(); 
      e[0]/=len; e[1]/=len; e[2]/=len; 
    }

    inline vec3 operator+(const vec3 &v2) const { return vec3(e[0] + v2.e[0], e[1] + v2.e[1], e[2] + v2.e[2]); }
    inline vec3 operator-(const vec3 &v2) const { return vec3(e[0] - v2.e[0], e[1] - v2.e[1], e[2] - v2.e[2]); }
    inline vec3 operator*(const vec3 &v2) const { return vec3(e[0] * v2.e[0], e[1] * v2.e[1], e[2] * v2.e[2]); }
    inline vec3 operator/(const vec3 &v2) const  { return vec3(e[0] / v2.e[0], e[1] / v2.e[1], e[2] / v2.e[2]); }
    inline vec3 operator+(const double d) const { return vec3(e[0] + d, e[1] + d, e[2] + d); }
    inline vec3 operator-(const double d) const { return vec3(e[0] - d, e[1] - d, e[2] - d); }
    inline vec3 operator*(const double d) const { return vec3(e[0] * d, e[1] * d, e[2] * d); }
    inline vec3 operator/(const double d) const { return vec3(e[0] / d, e[1] / d, e[2] / d); }

    inline double dot(const vec3 &v2) { return e[0]*v2.e[0] + e[1]*v2.e[1] + e[2]*v2.e[2]; }
    inline vec3 cross(const vec3 &v2) { 
      return vec3(e[1]*v2.e[2] - e[2]*v2.e[1], 
                  e[0]*v2.e[2] - e[2]*v2.e[0], 
                  e[0]*v2.e[1] - e[1]*v2.e[0]);
    }
    inline vec3 unit() { return *this / length(); }

  private:
    double e[3];
};

#endif
