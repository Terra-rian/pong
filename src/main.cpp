#include "game.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    Game game;
    Game::showInfo();

    while(Game::isRunning()) {
        game.update();
        game.handleEvents();
        game.render();
    }

    return 0;
}