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
    Vector2D operator*(double scalar) const;

    /**
     * @brief Increments a vector by another vector.
     * @param rhs The vector to increment by.
     */
    Vector2D& operator+=(const Vector2D& rhs);

    /**
     * @brief Returns the x component of this vector.
     */
    [[nodiscard]] double getX() const;

    /**
     * @brief Returns the y component of this vector.
     */
    [[nodiscard]] double getY() const;

    /**
     * @brief Sets the x component of this vector.
     * @param X The x value to set.
     */
    void setX(double X);

    /**
     * @brief Sets the y component of this vector.
     * @param Y The y value to set.
     */
    void setY(double Y);

    /**
     * @brief Returns the magnitude of this vector.
     */
    [[nodiscard]] double magnitude() const;

    /**
     * @brief Returns the magnitude of this vector, squared.
     */
    [[maybe_unused]] [[nodiscard]] double magnitudeSquared() const;

    /**
     * @brief Returns the dot product between two vectors.
     * @param other The vector to multiply.
     */
    [[maybe_unused]] [[nodiscard]] double dot(const Vector2D& other) const;

    /**
     * @brief Returns the cross product between two vectors.
     * @param other The vector to multiply.
     */
    [[maybe_unused]] [[nodiscard]] Vector2D cross(const Vector2D& other) const;

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