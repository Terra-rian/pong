#include "vector2d.hpp"

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D& Vector2D::operator()() {
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const {
    return Vector2D(x + rhs.x, y + rhs.y);
}

Vector2D Vector2D::operator-() {
    return Vector2D(-x, -y);
}

Vector2D Vector2D::operator-(const Vector2D& rhs) const {
    return Vector2D(x - rhs.x, y - rhs.y);
}

Vector2D Vector2D::operator*(const double scalar) {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}

double Vector2D::magnitude() {
    return sqrt((pow(x, 2) + pow(y, 2)));
}

double Vector2D::magnitudeSquared() {
    return pow(magnitude(), 2);
}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::setX(const double x) {
    this->x = x;
}

void Vector2D::setY(const double y) {
    this->y = y;
}

double Vector2D::dot(const Vector2D& other) const {
    return (x * other.x) + (y * other.y);
}

Vector2D Vector2D::cross(const Vector2D& other) const {
    return Vector2D(x * other.x, y * other.y);
}