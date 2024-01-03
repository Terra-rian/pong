#pragma once

#include "globals.hpp"

/**
 * @brief Represents a paddle controlled by a player.
 */
class Paddle {
    public:
    /**
     * @brief Constructs a new `Paddle` object.
     * @param paddleImage The image of the paddle.
     * @param x The x coordinate of the paddle.
     * @param y The y coordinate of the paddle.
     */
    Paddle(SDL_Surface *paddleImage, const double x, const double y);

    /**
     * @brief Destructor for a `Paddle` object.
     */
    ~Paddle();

    /**
     * @brief Returns a rectangle representing the bounds of the paddle.
     */
    SDL_Rect* getRect();

    /**
     * @brief Shows the paddle on the game window.
     */
    void show();

    /**
     * @brief Moves the paddle up.
     */
    void moveUp();

    /**
     * @brief Moves the paddle down.
     */
    void moveDown();

    /**
     * @brief Returns the paddle's speed.
     */
    double getSpeed() const;

    /**
     * @brief Sets the paddle's speed.
     * @param speed The speed of the paddle to set.
     */
    void setSpeed(const double speed);

    /**
     * @brief Returns the score of a player.
     */
    int getScore();

    /**
     * @brief Adds a point to the player who scored.
     */
    void addScore();

    /**
     * @brief Adds a hit when a ball collides with a paddle.
     */
    static void addHit();

    /**
     * @brief Returns the number of times a ball has hit a paddle.
     */
    static int getHits();

    /**
     * @brief Resets the paddle hit count to 0.
     */
    static void resetHitCount();

    /**
     * @brief Resets a player's score to 0.
     */
    void resetScore();

    /**
     * @brief The current state of keys that are pressed/released.
     */
    const std::uint8_t* keyState;

    private:
    /**
     * @brief How fast the paddle can move up or down in pixels.
     */
    const double Y_SPEED = 6.0;

    /**
     * @brief The width of the paddle in pixels.
     */
    const int PADDLE_WIDTH = 10;

    /**
     * @brief The height of the paddle in pixels.
     */
    const int PADDLE_HEIGHT = 75;

    /**
     * @brief The amount of times a ball has hit a paddle.
     */
    static int hits;

    /**
     * @brief The current score of the player of this paddle.
     */
    int score;

    /**
     * @brief How fast the paddle is going up or down.
     */
    double ySpeed;

    /**
     * @brief The `SDL_Surface` of the image representing a paddle.
     */
    SDL_Surface* paddleSurface;

    /**
     * @brief The texture of the image representing a paddle.
     */
    SDL_Texture* paddleTexture;

    /**
     * @brief Represents the bounds of the paddle.
     */
    SDL_Rect paddleRect;
};