#include "image.hpp"

Image::Image() {
    imageOpened = false;

    if(!imageOpened) {
        if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
            LogFatal << "SDL_image couldn't be initialized. Error:" << IMG_GetError() << "\n";
            imageOpened = false;
        } else {
            LogInfo << "SDL_image initialized successfully.\n";
            imageOpened = true;
        }
    } else {
        LogInfo << "SDL_image initialized successfully.\n";
    }
}

bool Image::isImageOpen() const {
    return imageOpened;
}

SDL_Surface* Image::loadBMP(const std::string& path, int colorKeyState, std::array<std::uint32_t, 3>& colorKey) {
    SDL_Surface* image = SDL_LoadBMP(path.c_str());

    if(image == nullptr) {
        LogFatal << "Failed to load an image. Error: " << IMG_GetError() << "\n";
    } else {
        SDL_SetColorKey(image, colorKeyState, SDL_MapRGB(image->format, colorKey[0], colorKey[1], colorKey[2]));
    }

    return image;
}

SDL_Surface* Image::loadBMP(const std::string &path, std::array<std::uint32_t, 3>& colorKey) {
    return loadBMP(path, SDL_TRUE, colorKey);
}

SDL_Surface* Image::loadBMP(const std::string &path) {
    std::array<std::uint32_t, 3> colorKey{{0, 0, 0}};
    return loadBMP(path, SDL_FALSE, colorKey);
}

SDL_Surface* Image::loadPNG(const std::string &path) {
    SDL_Surface* image = nullptr;
    SDL_RWops* rwop = nullptr;

    if(imageOpened) {
        rwop = SDL_RWFromFile(path.c_str(), "rb");
        image = IMG_LoadPNG_RW(rwop);

        if(image == nullptr) {
            LogFatal << "Failed to load an image. Error: " << IMG_GetError() << "\n";
        }
    }

    return image;
}