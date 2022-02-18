#include <iostream>
#include <memory>
#include "SDL.h"
#include "Sprite.hpp"
#include "EntityTypes.hpp"
#include "BasicView.hpp"

namespace Monstrus::View {
    void BasicView::renderAll() {
        // For now, just test that SDL works
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(1000);
    }

    void BasicView::initAssets() {
        // For loading assets like images later on
        std::cout << "Initializing assets..." << std::endl;
        window = SDL_CreateWindow("Monstrus", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
        display = SDL_GetWindowSurface(window);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        loadAssets();
    }

    void BasicView::loadAssets() {
        // Just going to load one thing for now
        // entities->insert({Entities::EntityType::Knight, std::make_unique<Sprite>({NULL})});
    }

    BasicView::~BasicView() {
        SDL_DestroyWindow(window);
        for (auto& element : *entities) {
            element.second->destroy();
        }
        for (auto& element : *assets) {
            element.second->destroy();
        }
    }
}  // namespace Monstrus::View