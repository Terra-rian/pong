#include "font.hpp"
#include "window.hpp"

Font::Font(SDL_Rect &fontRect) : FontManager() {
    this->fontRect = fontRect;

    fontSurface = nullptr;
    fontTexture = nullptr;
}

void Font::openFont(FontType fontType, int size) {
    if(!isTTFOpened) {
        LogFatal << "The font was unable to be loaded.\n";
        return;
    }

    switch(fontType) {
        case FontType::NORMAL:
            fontName = "resources/fonts/OpenSans-Regular.ttf";
            break;

        case FontType::BOLD:
            fontName = "resources/fonts/OpenSans-Bold.ttf";
            break;

        case FontType::EXTRA_BOLD:
            fontName = "resources/fonts/OpenSans-ExtraBold.ttf";
            break;

        default:
            break;
    }

    font = TTF_OpenFont(fontName.c_str(), size);

    if(font == nullptr) {
        LogFatal << "Failed to load the font " << fontName << ". Error: " << TTF_GetError() << "\n";
    } else {
        LogInfo << "Font " << fontName << " loaded successfully.\n";
    }
}

void Font::renderTextSolid(const std::string &text) {
    if(font == nullptr) {
        LogWarning << "No font loaded.\n";
        return;
    }

    fontSurface = TTF_RenderText_Blended(font, text.c_str(), fontColor);

    if(fontSurface == nullptr) {
        LogFatal << "Failed to render font " << fontName << ". Error: " << TTF_GetError() << "\n";
        return;
    }

    fontTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), fontSurface);
    SDL_FreeSurface(fontSurface);

    if(fontTexture == nullptr) {
        LogFatal << "Font texture for font " << fontName << " not created. Error: " << TTF_GetError() << "\n";
        return;
    }

    SDL_RenderCopy(Window::getRenderer(), fontTexture, nullptr, &fontRect);
    SDL_DestroyTexture(fontTexture);
}

void Font::renderTextShaded(const std::string& text) {
    if(font == nullptr) {
        LogWarning << "No font loaded.\n";
        return;
    }

    fontSurface = TTF_RenderText_Shaded(font, text.c_str(), fontColor, shadedFontColor);

    if(fontSurface == nullptr) {
        LogFatal << "Failed to render font " << fontName << ". Error: " << TTF_GetError() << "\n";
        return;
    }

    fontTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), fontSurface);
    SDL_FreeSurface(fontSurface);

    if(fontTexture == nullptr) {
        LogFatal << "Font texture for font " << fontName << " not created. Error: " << TTF_GetError() << "\n";
        return;
    }

    SDL_RenderCopy(Window::getRenderer(), fontTexture, nullptr, &fontRect);
    SDL_DestroyTexture(fontTexture);
}

void Font::setFontColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
    fontColor.r = r;
    fontColor.b = g;
    fontColor.g = b;
    fontColor.a = a;
}