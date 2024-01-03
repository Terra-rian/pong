#pragma once

#include "globals.hpp"

/**
 * @brief Wrapper class for `SDL_ttf`, manages game fonts.
 */
class FontManager {
    public:
    /**
     * @brief Constructs a new `FontManager` object.
     */
    FontManager();

    /**
     * @brief Destructor for a `FontManager` object.
     */
    ~FontManager();

    protected:
    /**
     * @brief The internal pointer to a font.
     */
    TTF_Font* font;

    /**
     * @brief The color of the font.
     */
    SDL_Color fontColor{};

    /**
     * @brief The shaded color of the font.
     */
    SDL_Color shadedFontColor{};

    /**
     * @brief Is a font currently in use?
     */
    bool isTTFOpened;

    private:
    /**
     * @brief Initializes `SDL_ttf`.
     */
    [[nodiscard]] static bool initializeTTF() ;
};