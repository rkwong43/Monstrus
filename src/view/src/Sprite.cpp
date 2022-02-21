
#include "SDL.h"
#include "Sprite.hpp"

namespace Monstrus::View {
    Sprite::~Sprite() {
        // Destroys all surfaces inside its images
        for (auto i = 0; i < sprites->size(); i++) {
            SDL_FreeSurface(sprites->front());
            sprites->next();
        }
    }

    SDL_Surface* Sprite::getImage() { return sprites->front(); }
    void Sprite::animate() { sprites->next(); }
}  // namespace Monstrus::View