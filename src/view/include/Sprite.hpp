#pragma once

#include "IRenderable.hpp"

namespace Game::View {
    /**
     * @brief Represents a unit or item graphically.
     *
     */
    class Sprite : public IRenderable {
       public:
        void render() override = 0;
        void animate() override = 0;
    };
}  // namespace Game::View