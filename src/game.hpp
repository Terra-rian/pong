#pragma once

#include "globals.hpp"

#include "audio.hpp"
#include "ball.hpp"
#include "font.hpp"
#include "image.hpp"
#include "paddle.hpp"
#include "texture.hpp"
#include "window.hpp"

/**
 * @brief Abstract class representing the actual game of Pong.
 */
class Game {
    public:
    /**
     * @brief Constructs a new `Game` object.
     */
    Game();

    /**
     * @brief Updates the position of every object on the game screen.
     */
    void update();

    /**
     * @brief Renders all objects onto the game screen.
     */
    void render();

    /**
     * @brief Handles events received (such as keypresses).
     */
    void handleEvents();

    /**
     * @brief Returns the preferred FPS for the game window.
     */
    static std::uint32_t getFPS();

    /**
     * @brief Checks if the game is currently running.
     * @return True if the game is running, false otherwise.
     */
    static bool isRunning();

    /**
     * @brief Pauses / unpauses the game.
     */
    void pause();

    /**
     * @brief Renders the score labels onto the game window.
     */
    void renderScore();

    /**
     * @brief Updates the score based on which player has scored.
     */
    void updateScore();

    /**
     * @brief Restarts the game & resets the positions of all objects on the game window.
     */
    void restart();

    /**
     * @brief Resets the game & sets all objects to their default states.
     */
    void resetGame();

    /**
     * @brief Displays a window with information about the game.
     */
    void showInfo();

    /**
     * @brief Displays a window showing that player 1 won.
     */
    void player1Won();

    /**
     * @brief DIsplays a window showing that player 2 won.
     */
    void player2Won();

    /**
     * @brief Are we in debug mode?
     */
    static bool inDebugMode;

    /**
     * @brief The audio manager instance of the game window.
     */
    static std::shared_ptr<Audio> audio;

    private:
    /**
     * @brief Struct containing data for displaying player scores.
     */
    struct PlayerScores {
        /**
         * @brief The font for player 1's score.
         */
        std::shared_ptr<Font> fontPlayer1;

        /**
         * @brief The font for player 2's score.
         */
        std::shared_ptr<Font> fontPlayer2;

        /**
         * @brief The bounds for displaying player 1's score.
         */
        SDL_Rect rectFont1;

        /**
         * @brief The bounds for displaying player 2's score.
         */
        SDL_Rect rectFont2;
    } playerScores;

    /**
     * @brief Struct containing data for displaying debug info.
     */
    struct DebugInfo {
        /**
         * @brief The font for displaying debug info.
         */
        std::shared_ptr<Font> debugFont;

        /**
         * @brief The bounds for displaying debug info.
         */
        SDL_Rect debugFontRect;
    } debugInfo;

    /**
     * @brief The current event received by SDL2 from the OS.
     */
    SDL_Event event;

    /**
     * @brief The number of milliseconds since SDL initialization.
     */
    std::uint32_t currentTime;

    /**
     * @brief The actual FPS after accounting for delays.
     */
    static std::uint32_t actualFPS;

    /**
     * @brief The current FPS of the game.
     */
    static std::uint32_t FPS;

    /**
     * @brief Is the game running?
     */
    static bool isGameRunning;

    /**
     * @brief Is the game paused?
     */
    static bool isPaused;

    /**
     * @brief The texture for the pause message.
     */
    std::shared_ptr<Texture> pauseMessageTexture;

    /**
     * @brief The texture for the pause background.
     */
    std::shared_ptr<Texture> pauseBackgroundTexture;

    /**
     * @brief The paddle for player 1.
     */
    std::shared_ptr<Paddle> player1;

    /**
     * @brief The paddle for player 2.
     */
    std::shared_ptr<Paddle> player2;

    /**
     * @brief The ball displayed on the game screen.
     */
    std::shared_ptr<Ball> ball;

    /**
     * @brief The main game window, contains all entities.
     */
    std::shared_ptr<Window> window;

    /**
     * @brief An instance of the `Image` class to handle loading images.
     */
    std::shared_ptr<Image> image;
};