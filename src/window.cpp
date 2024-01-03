#include "window.hpp"

SDL_Window* Window::window;
SDL_Renderer* Window::renderer;

const int Window::WINDOW_WIDTH = 800, Window::WINDOW_HEIGHT = 600;

Window::Window(const std::string& title, int width, int height, std::uint32_t flags) {
    window = nullptr;
    renderer = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        LogFatal << "Couldn't initialize video & audio. Error: " << SDL_GetError() << "\n";
    } else {
        LogInfo << "SDL initialized successfully.\n";

        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(window == nullptr) {
            LogFatal << "Window couldn't be created. Error: " << SDL_GetError() << "\n";
        } else {
            SDL_ShowCursor(0);

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == nullptr) {
                LogFatal << "Window renderer couldn't be created. Error: " << SDL_GetError() << "\n";
            } else {
                SDL_SetRenderDrawColor(renderer, 0x20, 0x20, 0x20, 1);
            }
        }
    }
}

Window::~Window() {
    if(renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if(window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

SDL_Window* Window::getWindow() {
   return window;
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}