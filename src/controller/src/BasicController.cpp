#include "BasicController.hpp"
#include "SDL.h"

namespace Game::Controller {
    void BasicController::start() {
        // SDL2 initialization
        SDL_Init(SDL_INIT_EVERYTHING);
        this->view->initAssets();
        // Main game loop
        // For now, this is just the game loop for a single instance/fight. Will add menus and the tavern later on
        while (true) {
            this->processInput();
            this->model->update();
            this->view->render();
            // Temporary until I add SDL's clock
            break;
        }
        SDL_Quit();
    }

    void BasicController::processInput() {}
}  // namespace Game::Controller