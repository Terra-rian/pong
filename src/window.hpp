#pragma once

#include "globals.hpp"

/**
 * @brief Represents the main window of the game.
 */
class Window {
    public:
    /**
     * @brief Creates a new `Window` object.
     * @param title The title of the game window.
     * @param width The width of the game window.
     * @param height The height of the game window.
     * @param flags The flags setted to the game window.
     */
    Window(const std::string& title, int width, int height, std::uint32_t flags);
    Window() = delete;

    /**
     * @brief Destructor for a `Window` object.
     */
    ~Window();

    /**
     * @brief Returns the current instance of the game window.
     */
    static SDL_Window* getWindow();

    /**
     * @brief Returns the current instance of the game renderer.
     */
    static SDL_Renderer* getRenderer();

    /**
     * @brief The width of the game window in pixels.
     */
    static const int WINDOW_WIDTH;

    /**
     * @brief The height of the game window in pixels.
     */
    static const int WINDOW_HEIGHT;

    private:
    /**
     * @brief The main window of the game.
     */
    static SDL_Window* window;

    /**
     * @brief The main renderer of the window.
     */
    static SDL_Renderer* renderer;
};