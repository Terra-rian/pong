#include "game.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
    Game game;
    game.showInfo();

    while(game.isRunning()) {
        game.update();
        game.handleEvents();
        game.render();
    }

    return 0;
}