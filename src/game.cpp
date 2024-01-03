#include "game.hpp"

std::uint32_t Game::FPS;
std::uint32_t Game::actualFPS;

bool Game::isGameRunning;
bool Game::isPaused;
bool Game::inDebugMode;

std::shared_ptr<Audio> Game::audio;

Game::Game() {
    FPS = 60;
    isPaused = false;
    isGameRunning = true;
    inDebugMode = false;

    std::string leftpaddle("resources/icons/leftpaddle.bmp");
    std::string rightpaddle("resources/icons/rightpaddle.bmp");
    std::string ball("resources/icons/ball.png");
    std::string pauseBackground("resources/icons/pause-background.png");
    std::string pauseMessage("resources/icons/pause.png");

    window = std::make_shared<Window>("Pong: The Definitive Edition", Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    image = std::make_shared<Image>();
    audio = std::make_shared<Audio>();

    playerScores.rectFont1.h = 120;
    playerScores.rectFont1.w = 50;
    playerScores.rectFont1.x = Window::WINDOW_WIDTH / 2 - 200;
    playerScores.rectFont1.y = Window::WINDOW_HEIGHT / 2 - 230;

    playerScores.rectFont2.h = 120;
    playerScores.rectFont2.w = 50;
    playerScores.rectFont2.x = Window::WINDOW_WIDTH / 2 + 150;
    playerScores.rectFont2.y = Window::WINDOW_HEIGHT / 2 - 230;

    playerScores.fontPlayer1 = std::make_shared<Font>(playerScores.rectFont1);
    playerScores.fontPlayer2 = std::make_shared<Font>(playerScores.rectFont2);

    playerScores.fontPlayer1->openFont(Font::FontType::BOLD, 400);
    playerScores.fontPlayer2->openFont(Font::FontType::BOLD, 400);

    playerScores.fontPlayer1->setFontColor(200, 200, 200, 255);
    playerScores.fontPlayer2->setFontColor(200, 200, 200, 255);

    debugInfo.debugFontRect.h = 50;
    debugInfo.debugFontRect.w = 100;
    debugInfo.debugFontRect.x = Window::WINDOW_WIDTH - 110;
    debugInfo.debugFontRect.y = 10;

    debugInfo.debugFont = std::make_shared<Font>(debugInfo.debugFontRect);
    debugInfo.debugFont->openFont(Font::FontType::NORMAL, 300);
    debugInfo.debugFont->setFontColor(200, 200, 200, 255);

    player1 = std::make_shared<Paddle>(image->loadBMP(leftpaddle), 1, Window::WINDOW_HEIGHT / 2 - 25);
    player2 = std::make_shared<Paddle>(image->loadBMP(rightpaddle), Window::WINDOW_WIDTH - 11, Window::WINDOW_HEIGHT / 2 - 25);

    this->ball = std::make_shared<Ball>(image->loadPNG(ball), Window::WINDOW_WIDTH / 2, Window::WINDOW_HEIGHT / 2);

    pauseBackgroundTexture = std::make_shared<Texture>();
    pauseMessageTexture = std::make_shared<Texture>();

    pauseBackgroundTexture->loadTexture(image->loadPNG(pauseBackground), Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT, 0, 0);
    pauseMessageTexture->loadTexture(image->loadPNG(pauseMessage), 188, 34, Window::WINDOW_WIDTH / 2 - 94, Window::WINDOW_HEIGHT / 2 - 17);

    audio->playMusic(Audio::Music::TRACK_1, 0);
    audio->playMusic(Audio::Music::TRACK_2, 0);
    audio->playMusic(Audio::Music::TRACK_3, 0);
}

void Game::update() {
    currentTime = SDL_GetTicks();

    ball->move(player1->getRect(), player2->getRect());
    updateScore();

    if(1000 / getFPS() > (SDL_GetTicks() - currentTime)) {
        actualFPS = 1000 / getFPS() - (SDL_GetTicks() - currentTime);
        SDL_Delay(actualFPS);
    }
}

void Game::handleEvents() {
    player1->keyState = SDL_GetKeyboardState(nullptr);
    player2->keyState = SDL_GetKeyboardState(nullptr);

    if(player1->keyState[SDL_SCANCODE_W]) {
        player1->moveUp();
    }

    if(player1->keyState[SDL_SCANCODE_S]) {
        player1->moveDown();
    }

    if(player2->keyState[SDL_SCANCODE_UP]) {
        player2->moveUp();
    }

    if(player2->keyState[SDL_SCANCODE_DOWN]) {
        player2->moveDown();
    }

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                isGameRunning = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        isGameRunning = false;
                        break;

                    case SDLK_r:
                        restart();
                        break;

                    case SDLK_d:
                    case SDLK_F5:
                        inDebugMode = !inDebugMode;
                        break;

                    case SDLK_f: {
                        int fullscreenFlag = SDL_GetWindowFlags(Window::getWindow());

                        if((fullscreenFlag & SDL_WINDOW_FULLSCREEN) == SDL_WINDOW_FULLSCREEN) {
                            SDL_SetWindowFullscreen(Window::getWindow(), 0);
                        } else {
                            SDL_SetWindowFullscreen(Window::getWindow(), SDL_WINDOW_FULLSCREEN);
                        }

                        break;
                    }

                    case SDLK_p:
                        pause();
                        break;

                    case SDLK_i:
                        showInfo();
                        break;

                    default:
                        break;
                }

            default:
                break;
        }
    }
}

void Game::render() {
    SDL_RenderClear(Window::getRenderer());

    player1->show();
    player2->show();
    ball->show();

    renderScore();

    if(inDebugMode) {
        debugInfo.debugFont->renderTextSolid("FPS: " + std::to_string(actualFPS));
    }

    if(isPaused) {
        pauseMessageTexture->show();
        pauseBackgroundTexture->show();
    }

    SDL_RenderPresent(Window::getRenderer());
}

void Game::renderScore() {
    playerScores.fontPlayer1->renderTextSolid(std::to_string(player1->getScore()));
    playerScores.fontPlayer2->renderTextSolid(std::to_string(player2->getScore()));
}

bool Game::isRunning() {
    return isGameRunning;
}

std::uint32_t Game::getFPS() {
    return FPS;
}

void Game::pause() {
    if(!isPaused) {
        ball->setXSpeed(0.0);
        ball->setYSpeed(0.0);

        player1->setSpeed(0.0);
        player2->setSpeed(0.0);

        isPaused = true;
    } else {
        ball->setXSpeed(ball->getLastVelocity().getX());
        ball->setYSpeed(ball->getLastVelocity().getY());

        player1->setSpeed(6.0);
        player2->setSpeed(6.0);

        isPaused = false;
    }
}

void Game::updateScore() {
    SDL_Rect* ballRect = ball->getRect();

    if(ballRect->x + ballRect->w > Window::WINDOW_WIDTH) {
        player1->addScore();
        resetGame();

        LogInfo << "Player 1 score: " << player1->getScore() << "\n";
    }

    if(ballRect->x + ballRect->w < 0) {
        player2->addScore();
        resetGame();

        LogInfo << "Player 2 score: " << player2->getScore() << "\n";
    }

    if(player1->getScore() == 11) {
        player1Won();
        restart();
    }

    if(player2->getScore() == 11) {
        player2Won();
        restart();
    }
}

void Game::resetGame() {
    SDL_Rect* ballRect = ball->getRect();

    SDL_Rect* rectPlayer1 = player1->getRect();
    SDL_Rect* rectPlayer2 = player2->getRect();

    Paddle::resetHitCount();

    ball->setXSpeed(ball->getRandomPosition(-5, 5));
    ball->setYSpeed(ball->getRandomPosition(-3, 3));

    ball->setLastVelocity(ball->getVelocity());

    ballRect->x = Window::WINDOW_WIDTH / 2 - ballRect->w;
    ballRect->y = Window::WINDOW_HEIGHT / 2 - ballRect->h;

    rectPlayer1->y = Window::WINDOW_HEIGHT / 2 - (rectPlayer1->h / 2);
    rectPlayer2->y = Window::WINDOW_HEIGHT / 2 - (rectPlayer2->h / 2);
}

void Game::restart() {
    player1->resetScore();
    player2->resetScore();

    resetGame();
}

void Game::showInfo() {
    std::string title = "Pong: How to Play";
    std::string rules = "Pong is a two-dimensional sports game that simulates table tennis.\nPlayers use the paddles to hit a ball back and forth.\nThe goal is for each player to reach eleven points before the opponent.\nPoints are earned when one fails to return the ball to the other.\n\n";
    std::string keybinds = "Player 1 (Red): W / S\nPlayer 2 (Blue): Up / down arrows\n\nESC / Q: Quits the app\nR: Restarts the game\nD / F5: Toggles debug mode\nF: Toggles fullscreen mode\nP: Pauses the game\nI: Shows this modal";
    
    if(SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title.c_str(), (rules + keybinds).c_str(), Window::getWindow()) != 0) {
        LogFatal << "Couldn't show info message box. Error: " << SDL_GetError() << "\n";
    }
}

void Game::player1Won() {
    std::string title = "Player 1: WINNER";
    std::string msg = "Player 1 wins the game!\nPress the button below to restart the game!";

    if(SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title.c_str(), msg.c_str(), Window::getWindow()) != 0) {
        LogFatal << "Couldn't show player 1 win message box. Error: " << SDL_GetError() << "\n";
    }
}

void Game::player2Won() {
    std::string title = "Player 2: WINNER";
    std::string msg = "Player 2 wins the game!\nPress the button below to restart the game!";

    if(SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title.c_str(), msg.c_str(), Window::getWindow()) != 0) {
        LogFatal << "Couldn't show player 2 win message box. Error: " << SDL_GetError() << "\n";
    }
}