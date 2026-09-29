#pragma once
#include <cmath>
#include <ostream>

class Vec3 {
public:
  double e[3];

  Vec3() : e{0, 0, 0} {}
  Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }

  Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
  double operator[](int idx) const { return e[idx]; }
  double &operator[](int idx) { return e[idx]; }

  Vec3 &operator+=(const Vec3 &other) {
    e[0] += other.x();
    e[1] += other.y();
    e[2] += other.z();
    return *this;
  }

  Vec3 operator*=(double s) {
    e[0] *= s;
    e[1] *= s;
    e[2] *= s;
    return *this;
  }

  Vec3 operator/=(double s) { return *this *= (1 / s); }

  double length() { return std::sqrt(length_squared()); }

  double length_squared() { return x() * x() + y() * y() + z() * z(); }
};

using Point3 = Vec3;

inline Vec3 operator+(const Vec3 &first, const Vec3 &other) {
  return Vec3(first.x() + other.x(), first.y() + other.y(),
              first.z() + other.z());
}

inline Vec3 operator-(const Vec3 &first, const Vec3 &other) {
  return Vec3(first.x() - other.x(), first.y() - other.y(),
              first.z() - other.z());
}

inline Vec3 operator*(const Vec3 &first, const Vec3 &other) {
  return Vec3(first.x() * other.x(), first.y() * other.y(),
              first.z() * other.z());
}

inline Vec3 operator*(const double s, const Vec3 &v) {
  return Vec3(s * v.x(), s * v.y(), s * v.z());
}

inline Vec3 operator*(const Vec3 &v, const double s) { return s * v; }
inline Vec3 operator/(const Vec3 &v, const double s) { return v * (1 / s); }

inline double dot(Vec3 &u, Vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline Vec3 cross(Vec3 &u, Vec3 &v) {
  return Vec3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x());
}

inline Vec3 unit_vec(Vec3 u) { return u / u.length(); }

inline std::ostream &operator<<(std::ostream &out, const Vec3 v) {
  return out << v.x() << " " << v.y() << " " << v.z();
}
