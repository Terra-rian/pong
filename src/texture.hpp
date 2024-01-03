#pragma once

#include "globals.hpp"

/**
 * @brief A utility class to handle textures.
 */
class Texture {
    public:
    /**
     * @brief Constructs a new `Texture` object.
     */
    Texture();

    /**
     * @brief Destructor for a `Texture` object.
     */
    ~Texture();

    /**
     * @brief Loads a texture from an `SDL_Surface`.
     * @param imageSurface The surface containing the image.
     * @param width The width of the texture.
     * @param height The height of the texture.
     * @param x The x coordinate of the texture.
     * @param y The y coordinate of the texture.
     */
    void loadTexture(SDL_Surface* imageSurface, const int width, const int height, const int x, const int y);

    /**
     * @brief Blits the texture onto the renderer.
     */
    void show();

    private:
    /**
     * @brief Represents the texture of an image.
     */
    SDL_Texture* texture;

    /**
     * @brief Represents the bounds of an image.
     */
    SDL_Rect textureRect;
};