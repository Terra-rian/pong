#pragma once

#include "globals.hpp"
#include "vector2d.hpp"

/**
 * @brief Represents a ball on the game screen.
 */
class Ball {
    public:
    /**
     * @brief Constructs a new `Ball` object.
     * @param ballSurface The SDL surface for the ball sprite.
     * @param x The ball's x position.
     * @param y The ball's y position.
     */
    Ball(SDL_Surface* ballSurface, const double x, const double y);

    /**
     * @brief Destructor for a `Ball` object.
     */
    ~Ball();

    /**
     * @brief Called to show the ball in the screen.
     */
    void show();

    /**
     * @brief Moves the ball, reacts to collisions with borders & paddles.
     */
    void move(SDL_Rect* player1, SDL_Rect* player2);

    /**
     * @brief Returns the velocity vector of the ball.
     */
    Vector2D getVelocity() const;

    /**
     * @brief Returns the last velocity vector of the ball.
     */
    Vector2D getLastVelocity() const;

    /**
     * @brief Sets the last velocity vector of the ball.
     * @param lastVelocity The last velocity to set.
     */
    void setLastVelocity(const Vector2D& lastVelocity);

    /**
     * @brief Gets the ball's velocity's x component.
     * @return The ball's horizontal speed.
     */
    double getXSpeed() const;

    /**
     * @brief Gets the ball's velocity's y component.
     * @return The ball's vertical speed.
     */
    double getYSpeed() const;

    /**
     * @brief Returns a double between `a` and `b`.
     * @param a The least value possible.
     * @param b The largest value possible.
     * @return A random double between 2 doubles.
     */
    double getRandomPosition(double a, double b);

    /**
     * @brief Sets the ball's velocity's x component.
     * @param x The ball's horizontal speed to set.
     */
    void setXSpeed(double x);
    
    /**
     * @brief Sets the ball's velocity's y component.
     * @param y The ball's vertical speed to set.
     */
    void setYSpeed(double y);

    /**
     * @brief Returns the bounds of the ball.
     * @return A pointer to an `SDL_Rect` object that represents the bounds of the ball.
     */
    SDL_Rect* getRect();

    private:
    /**
     * @brief Increases the velocity of the ball by a random amount.
     */
    void increaseVelocity();

    /**
     * @brief Tests if the ball has collided with another object or the game bounds.
     * @param rectangle The rectangle to test against.
     * @return True if a collision has occurred, false otherwise.
     */
    bool collision(SDL_Rect* rectangle);

    /**
     * @brief The width of the ball in pixels.
     */
    const int BALL_WIDTH = 20;

    /**
     * @brief The height of the ball in pixels.
     */
    const int BALL_HEIGHT = 20;

    /**
     * @brief The ball's velocity vector.
     */
    Vector2D ballVelocity;

    /**
     * @brief Stores the last velocity of the ball (during game pause).
     */
    Vector2D lastBallVelocity;

    /**
     * @brief The surface that holds the ball's sprite.
     */
    SDL_Surface* ballSurface;

    /**
     * @brief The texture that holds the ball's image.
     */
    SDL_Texture* ballTexture;

    /**
     * @brief Represents the ball's position on the game screen.
     */
    SDL_Rect ballRect;
};