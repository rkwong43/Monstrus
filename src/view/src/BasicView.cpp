#include <iostream>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.hpp"
#include "EntityTypes.hpp"
#include "BasicView.hpp"

namespace Monstrus::View {
    BasicView::~BasicView() {
        // Will also destroy the display surface
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }

    void BasicView::renderAll() {
        // For now, just test that SDL works
        // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        // Clearing the render buffer
        // SDL_RenderClear(renderer);
        for (auto& element : *assets) {
            // Figure out positions? Also change to use entities
            SDL_Rect pos;
            SDL_BlitScaled(element.second->getImage(), NULL, display, &pos);
        }
        // Displaying everything that is drawn with renderer
        SDL_UpdateWindowSurface(window);
        SDL_Delay(1000);
        // SDL_RenderPresent(renderer);
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
        auto flags = IMG_INIT_PNG;

        auto rawImage = IMG_Load("resources/images/Knight.png");
        auto optimizedImage = SDL_ConvertSurface(rawImage, display->format, 0);
        assets->insert({Entities::EntityType::Knight, std::make_unique<Sprite>(std::initializer_list{optimizedImage})});
        SDL_FreeSurface(rawImage);
    }
}  // namespace Monstrus::View