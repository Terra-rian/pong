#include "fontmanager.hpp"

FontManager::FontManager() {
    font = nullptr;
    isTTFOpened = false;

    fontColor.r = 0xff;
    fontColor.b = 0xff;
    fontColor.g = 0xff;
    fontColor.a = 1;

    shadedFontColor.r = 0x00;
    shadedFontColor.b = 0x00;
    shadedFontColor.g = 0x00;
    shadedFontColor.a = 1;

    isTTFOpened = initializeTTF();
}

FontManager::~FontManager() {
    TTF_CloseFont(font);
    TTF_Quit();
}

bool FontManager::initializeTTF() {
    if(isTTFOpened) {
        return true;
    } else {
        if(TTF_Init() != 0) {
            LogFatal << "SDL_ttf could not be initialized: " << TTF_GetError() << "\n";
            return false;
        } else {
            LogInfo << "SDL_ttf initialized successfully.\n";
            return true;
        }
    }
}