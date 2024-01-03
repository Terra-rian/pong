#pragma once

#include "globals.hpp"
#include "fontmanager.hpp"

/**
 * @brief Extends the `FontManager` class, utility class to allow text rendering.
 */
class Font : protected FontManager {
    public:
    /**
     * @brief Enum for all possible font types.
     */
    enum class FontType {
        NORMAL,
        BOLD,
        EXTRA_BOLD
    };

    /**
     * @brief Constructs a new `Font` object.
     */
    Font(SDL_Rect& fontRect);

    /**
     * @brief Initializes a font to be used.
     * @param fontType The type of font to use.
     * @param size The size of the font in pixels.
     */
    void openFont(FontType fontType, int size);

    /**
     * @brief Renders solid text on the game window.
     * @param text The text to render.
     */
    void renderTextSolid(const std::string& text);

    /**
     * @brief Renders shaded text on the game window.
     * @param text The text to render.
     */
    void renderTextShaded(const std::string& text);

    /**
     * @brief Sets the color of the font to be rendered (RGBA).
     * @param r Red shift.
     * @param g Green shift.
     * @param b Blue shift.
     * @param a Alpha channel (transparency).
     */
    void setFontColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);

    private:
    /**
     * @brief The position of the font to be rendered.
     */
    SDL_Rect fontRect;

    /**
     * @brief The surface that contains the rendered font.
     */
    SDL_Surface* fontSurface;

    /**
     * @brief The texture to be drawn on the screen.
     */
    SDL_Texture* fontTexture;

    /**
     * @brief The name of the font.
     */
    std::string fontName;
};