#include "vector2d.hpp"

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D& Vector2D::operator()() {
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vector2D Vector2D::operator-() {
    return {-x, -y};
}

Vector2D Vector2D::operator-(const Vector2D& rhs) const {
    return {x - rhs.x, y - rhs.y};
}

Vector2D Vector2D::operator*(const double scalar) const {
    return {x * scalar, y * scalar};
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}

double Vector2D::magnitude() const {
    return sqrt((pow(x, 2) + pow(y, 2)));
}

[[maybe_unused]] double Vector2D::magnitudeSquared() const {
    return pow(magnitude(), 2);
}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::setX(const double X) {
    this->x = X;
}

void Vector2D::setY(const double Y) {
    this->y = Y;
}

[[maybe_unused]] double Vector2D::dot(const Vector2D& other) const {
    return (x * other.x) + (y * other.y);
}

[[maybe_unused]] Vector2D Vector2D::cross(const Vector2D& other) const {
    return {x * other.x, y * other.y};
}