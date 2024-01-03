#include "paddle.hpp"
#include "game.hpp"
#include "window.hpp"

int Paddle::hits;

Paddle::Paddle(SDL_Surface* paddleImage, const double x, const double y) {
    if(paddleImage == nullptr) {
        LogFatal << "The paddle texture is null, ensure that the resources folder is in the same directory as the executable.\n";
    } else {
        score = 0;
        ySpeed = Y_SPEED;

        paddleSurface = paddleImage;
        paddleRect.x = static_cast<int>(x);
        paddleRect.y = static_cast<int>(y);
        paddleRect.w = PADDLE_WIDTH;
        paddleRect.h = PADDLE_HEIGHT;

        paddleTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), paddleImage);

        if(paddleTexture == nullptr) {
            LogFatal << "Failed to create paddle texture. Error: " <<  SDL_GetError() << "\n";
        }

        SDL_FreeSurface(paddleImage);

        if( paddleTexture != nullptr) {
            LogInfo << "Paddle created successfully.\n";
        }
    }
}

Paddle::~Paddle() {
    if(paddleTexture != nullptr) {
        SDL_DestroyTexture(paddleTexture);
    }
}

void Paddle::show() {
    SDL_RenderCopy(Window::getRenderer(), paddleTexture, nullptr, &paddleRect);
}

void Paddle::moveUp() {
    if(paddleRect.y > 0) {
        paddleRect.y -= static_cast<int>(Y_SPEED);
    }
}

void Paddle::moveDown() {
    if(paddleRect.y + paddleRect.h < Window::WINDOW_HEIGHT) {
        paddleRect.y += static_cast<int>(Y_SPEED);
    }
}

SDL_Rect* Paddle::getRect() {
    return &paddleRect;
}

[[maybe_unused]] double Paddle::getSpeed() const {
    return ySpeed;
}

void Paddle::setSpeed(const double speed) {
    ySpeed = speed;
}

int Paddle::getScore() const {
    return score;
}

void Paddle::resetScore() {
    score = 0;
}

void Paddle::addScore() {
    if(Game::audio->isAudioOpen()) {
        Game::audio->playEffect(Audio::EffectType::SCORE_UP);
    }

    score++;
}

int Paddle::getHits() {
    return hits;
}

void Paddle::addHit() {
    hits++;
}

void Paddle::resetHitCount() {
    hits = 0;
}