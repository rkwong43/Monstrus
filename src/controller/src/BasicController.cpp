#include <iostream>
#include "BasicController.hpp"
#include "SDL.h"

namespace Monstrus::Controller {
    void BasicController::start() {
        // SDL2 initialization
        SDL_Init(SDL_INIT_EVERYTHING);
        this->view->initAssets();
        // Main game loop
        // For now, this is just the game loop for a single instance/fight. Will add menus and the tavern later on
        int counter = 0;
        std::cout << "Starting game loop..." << std::endl;
        while (counter < 20) {
            this->processInput();
            this->model->update();
            // TODO: Add some way to pass variables through to render
            this->view->renderAll();
            // Temporary until I add SDL's clock
            counter++;
        }
        SDL_Quit();
    }

    void BasicController::processInput() {}
}  // namespace Monstrus::Controller