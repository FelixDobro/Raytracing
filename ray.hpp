#pragma once

#include "vec3.hpp"

class Ray {
public:
  Ray() {}

  Ray(const Point3 &orig, const Vec3 &dir) : orig(orig), dir(dir) {}

  const Point3 &origin() const { return orig; }

  Point3 at(double t) const { return orig + t * dir; }

  const Vec3 &direction() const { return dir; }

private:
  Point3 orig;
  Vec3 dir;
};