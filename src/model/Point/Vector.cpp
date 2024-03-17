#include "Vector.h"

Vector::Vector() : x(0.0), y(0.0) {}
Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }

double Vector::length() const {
    return std::sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector &other) const {
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(double scalar) const {
    return Vector(x * scalar, y * scalar);
}

std::ostream &operator<<(std::ostream &os, const Vector &vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

double distance(const Vector &v1, const Vector &v2) {
    Vector diff = v2 - v1;
    return diff.length();
}

double operator*(const Vector &v1, const Vector &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}