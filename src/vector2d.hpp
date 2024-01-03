#pragma once

#include "globals.hpp"

/**
 * @brief Represents a vector with x and y components.
 */
class Vector2D {
    public:
    /**
     * @brief Constructs a new `Vector2D` object.
     * @param x The x position of the vector.
     * @param y The y position of the vector.
     */
    Vector2D(double x, double y);

    /**
     * @brief Returns the instance of this vector.
     */
    Vector2D& operator()();

    /**
     * @brief Adds two vectors (adds their components then returns a new vector containing the results).
     * @param rhs The vector to add.
     */
    Vector2D operator+(const Vector2D& rhs) const;

    /**
     * @brief Returns the inverse of this vector (reverses the signs of the components of the original vector).
     */
    Vector2D operator-();

    /**
     * @brief Subtracts two vectors (subtracts their components then returns a new vector containing the results).
     * @param rhs The vector to subtract.
     */
    Vector2D operator-(const Vector2D& rhs) const;

    /**
     * @brief Multiplies the components of this vector by a scalar.
    */
    Vector2D operator*(const double scalar);

    /**
     * @brief Increments a vector by another vector.
     * @param rhs The vector to increment by.
     */
    Vector2D& operator+=(const Vector2D& rhs);

    /**
     * @brief Returns the x component of this vector.
     */
    double getX() const;

    /**
     * @brief Returns the y component of this vector.
     */
    double getY() const;

    /**
     * @brief Sets the x component of this vector.
     * @param x The x value to set.
     */
    void setX(double x);

    /**
     * @brief Sets the y component of this vector.
     * @param y The y value to set.
     */
    void setY(double y);

    /**
     * @brief Returns the magnitude of this vector.
     */
    double magnitude();

    /**
     * @brief Returns the magnitude of this vector, squared.
     */
    double magnitudeSquared();

    /**
     * @brief Returns the dot product between two vectors.
     * @param other The vector to multiply.
     */
    double dot(const Vector2D& other) const;

    /**
     * @brief Returns the cross product between two vectors.
     * @param other The vector to multiply.
     */
    Vector2D cross(const Vector2D& other) const;

    private:
    /**
     * @brief The x component of this vector.
     */
    double x;

    /**
     * @brief The y component of this vector.
     */
    double y;
};