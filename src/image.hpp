#pragma once

#include "globals.hpp"

/**
 * @brief A utility class to handle BMP & PNG images.
 */
class Image {
    public:
    /**
     * @brief Constructs a new `Image` object.
     */
    Image();

    /**
     * @brief Checks if `SDL_image` was initialized successfully.
     */
    bool isImageOpen() const;

    /**
     * @brief Internal method, handles loading .bmp files.
     */
    SDL_Surface* loadBMP(const std::string& path, int colorKeyState, std::array<std::uint32_t, 3>& colorKey);

    /**
     * @brief Internal method, handles loading .bmp files.
     */
    SDL_Surface* loadBMP(const std::string& path, std::array<std::uint32_t, 3>& colorKey);

    /**
     * @brief Loads a .bmp file and returns an `SDL_Surface` containing data about the image.
     * @param path The path to the image, relative to the executable.
     */
    SDL_Surface* loadBMP(const std::string& path);

    /**
     * @brief Loads a .png file and returns an `SDL_Surface` containing data about the image.
     * @param path The path to the image, relative to the executable.
     */
    SDL_Surface* loadPNG(const std::string& path);

    private:
    /**
     * @brief Is an image open?
     */
    bool imageOpened;
};