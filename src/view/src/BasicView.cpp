#include <iostream>
#include "SDL.h"
#include "BasicView.hpp"

namespace Monstrus::View {
    void BasicView::renderAll() {
        // For now, just test that SDL works
        SDL_Window* window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(1000);

        SDL_DestroyWindow(window);
    }

    void BasicView::initAssets() {
        // For loading assets like images later on
        std::cout << "Initializing assets..." << std::endl;
    }
}  // namespace Monstrus::View