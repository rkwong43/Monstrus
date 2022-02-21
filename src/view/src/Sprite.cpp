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
    void Sprite::render() {}
    void Sprite::animate() {}
}  // namespace Monstrus::View