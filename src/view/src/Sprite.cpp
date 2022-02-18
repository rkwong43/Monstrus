#include "SDL.h"
#include "Sprite.hpp"

namespace Monstrus::View {

    void Sprite::render() {}
    void Sprite::animate() {}
    void Sprite::destroy() {
        // Destroys all surfaces inside its images
        /*
        for (auto i = 0; i < sprites->size(); i++) {
        }
        */
    }
}  // namespace Monstrus::View