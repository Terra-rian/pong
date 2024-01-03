#include "ball.hpp"
#include "game.hpp"
#include "paddle.hpp"
#include "random.hpp"
#include "window.hpp"

Ball::Ball(SDL_Surface* ballSurface, const double x, const double y) : ballVelocity(getRandomPosition(5, 7), getRandomPosition(-3, 3)), lastBallVelocity(ballVelocity()) {
    if(ballSurface == nullptr) {
        LogFatal << "The sprite for the ball was not loaded, please ensure that the resource folder is in the same directory as the executable.\n";
    } else {
        this->ballSurface = ballSurface;

        ballRect.x = static_cast<int>(x);
        ballRect.y = static_cast<int>(y);
        ballRect.w = BALL_WIDTH;
        ballRect.h = BALL_HEIGHT;

        ballTexture = SDL_CreateTextureFromSurface(Window::getRenderer(), ballSurface);

        if(ballTexture == nullptr) {
            LogFatal << "Failed to create ball texture. Error: " << SDL_GetError() << "\n";
        }

        SDL_FreeSurface(ballSurface);

        if(ballTexture != nullptr) {
            LogInfo << "Ball object created successfully.\n";
        }
    }
}

Ball::~Ball() {
    if(ballTexture != nullptr) {
        SDL_DestroyTexture(ballTexture);
    }
}

void Ball::show() {
    SDL_RenderCopy(Window::getRenderer(), ballTexture, nullptr, &ballRect);
}

void Ball::move(SDL_Rect* player1, SDL_Rect* player2) {
    ballRect.x += static_cast<int>(getXSpeed());
    ballRect.y += static_cast<int>(getYSpeed());

    // Y axis collision detection
    if(ballRect.y <= 0) {
        setYSpeed(-ballVelocity.getY());
        lastBallVelocity = ballVelocity;
    }

    if(ballRect.y + ballRect.h > Window::WINDOW_HEIGHT) {
        setYSpeed(-ballVelocity.getY());
        lastBallVelocity = ballVelocity;
    }

    // Paddle & goal collision detection
    if(collision(player1)) {
        if(ballRect.x + abs(getXSpeed()) < player1->x + player1->w) {
            setYSpeed(-ballVelocity.getY());
        } else {
            if(Paddle::getHits() == 3) {
                increaseVelocity();
                setXSpeed(-ballVelocity.getX());

                Paddle::resetHitCount();
            } else {
                setXSpeed(-ballVelocity.getX());
            }
        }

        lastBallVelocity = ballVelocity;

        if(Game::audio->isAudioOpen()) {
            Game::audio->playEffect(Audio::EffectType::PADDLE_HIT);
        }

        LogInfo << "Player 1 hit count: " << Paddle::getHits() << "\n";
        Paddle::addHit();
    }

    if(collision(player2)) {
        if((ballRect.x + ballRect.w) - getXSpeed() > player2->x) {
            setYSpeed(-ballVelocity.getY());
        } else {
            setXSpeed(-ballVelocity.getX());

            if(Paddle::getHits() == 3) {
                increaseVelocity();
                Paddle::resetHitCount();
            }
        }

        lastBallVelocity = ballVelocity;

        if(Game::audio->isAudioOpen()) {
            Game::audio->playEffect(Audio::EffectType::PADDLE_HIT);
        }

        LogInfo << "Player 2 hit count: " << Paddle::getHits() << "\n";
        Paddle::addHit();
    }
}

void Ball::increaseVelocity() {
    if(getXSpeed() < 0.0) {
        if(ballVelocity.getX() >= -8 && ballVelocity.getY() >= -6) {
            ballVelocity += ballVelocity() * Random::getReal(0.5, 1.5);
            lastBallVelocity = ballVelocity;
        }
    } else {
        if(ballVelocity.getX() <= 8 && ballVelocity.getY() <= 6) {
            ballVelocity += ballVelocity() * Random::getReal(0.5, 1.5);
            lastBallVelocity = ballVelocity;
        }
    }

    LogInfo << "New ball velocity components: (" << getXSpeed() << ", " << getYSpeed() << ")\n";
}

bool Ball::collision(SDL_Rect* rectangle) const {
    if(ballRect.y >= rectangle->y + rectangle->h) {
        return false;
    }

    if(ballRect.x >= rectangle->x + rectangle->w) {
        return false;
    }

    if(ballRect.y + ballRect.h <= rectangle->y) {
        return false;
    }

    if(ballRect.x + ballRect.w <= rectangle->x) {
        return false;
    }

    return true;
}

SDL_Rect* Ball::getRect() {
    return &ballRect;
}

Vector2D Ball::getVelocity() const {
    return ballVelocity;
}

Vector2D Ball::getLastVelocity() const {
    return lastBallVelocity;
}

double Ball::getXSpeed() const {
    return ballVelocity.getX();
}

double Ball::getYSpeed() const {
    return ballVelocity.getY();
}

double Ball::getRandomPosition(double a, double b) {
    double position;

    do {
        position = Random::getReal(a, b);
    } while((position >= 0.0 && position <= 3.0) || (position <= -0.0 && position >= -2.0));

    return position;
}

void Ball::setXSpeed(double x) {
    ballVelocity.setX(x);
}

void Ball::setYSpeed(double y) {
    ballVelocity.setY(y);
}

void Ball::setLastVelocity(const Vector2D& lastVelocity) {
    lastBallVelocity = lastVelocity;
}