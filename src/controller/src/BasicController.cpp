#include <iostream>
#include "BasicController.hpp"
#include "SDL.h"

namespace Monstrus::Controller {
    void BasicController::start() {
        // SDL2 initialization
        SDL_Init(SDL_INIT_EVERYTHING);
        // Main game loop
        // For now, this is just the game loop for a single instance/fight. Will add menus and the tavern later on

        // Handles game events
        // TODO: Maybe make it dynamically allocated instead of just on the stack?
        std::unique_ptr<SDL_Event> eventHandler = std::make_unique<SDL_Event>();
        std::cout << "Starting game loop..." << std::endl;
        // TODO: Remove the game over condition later
        while (!processInput(eventHandler.get()) && !model->isGameOver()) {
            model->update();
            // TODO: Add some way to pass variables through to render
            view->renderAll();
        }
        SDL_Quit();
    }

    bool BasicController::processInput(SDL_Event * e) {
        while (SDL_PollEvent(e) != 0) {
            if (e->type == SDL_QUIT) {
                return true;
            }
        }
        return false;
    }
}  // namespace Monstrus::Controller