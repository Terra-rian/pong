#include "texture.hpp"
#include "window.hpp"

Texture::Texture() {
    texture = nullptr;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

void Texture::loadTexture(SDL_Surface* imageSurface, const int width, const int height, const int x, const int y) {
    textureRect.h = height;
    textureRect.w = width;
    textureRect.x = x;
    textureRect.y = y;

    texture = SDL_CreateTextureFromSurface(Window::getRenderer(), imageSurface);
    SDL_FreeSurface(imageSurface);

    if(texture == nullptr) {
        LogFatal << "Image texture is null. Error: " << SDL_GetError() << "\n";
    }
}

void Texture::show() {
    if(texture == nullptr) {
        LogFatal << "Image texture is null. error: " << SDL_GetError() << "\n";
    } else {
        SDL_RenderCopy(Window::getRenderer(), texture, nullptr, &textureRect);
    }
}