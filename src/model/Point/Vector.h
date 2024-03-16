#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y;

public:
    Vector();
    Vector(double x, double y);

    double getX() const;
    double getY() const;

    double length() const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(double scalar) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector &vec);
    friend double operator*(const Vector &v1, const Vector &v2);

};

double distance(const Vector &v1, const Vector &v2);
double operator*(const Vector &v1, const Vector &v2);

#endif // VECTOR_H