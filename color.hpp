#pragma once

#include "vec3.hpp"
#include <ostream>

using Color = Vec3;

void write_color(std::ostream &out, const Color &pixel) {
  auto r = pixel.x();
  auto g = pixel.y();
  auto b = pixel.z();
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}