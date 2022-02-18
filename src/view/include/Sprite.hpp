#pragma once

#include <memory>
#include "SDL.h"
#include "IRenderable.hpp"
#include "LinkedList.hpp"

namespace Monstrus::View {
    /**
     * @brief Represents a unit or item graphically.
     *
     */
    class Sprite : public IRenderable {
       public:
        Sprite(std::initializer_list<SDL_Surface*> images) { sprites = std::make_unique<Utils::ConstLinkedList<SDL_Surface*>>(images); }

        void render() override;
        void animate() override;
        void destroy() override;

       private:
        std::unique_ptr<Utils::ConstLinkedList<SDL_Surface*>> sprites;
    };
}  // namespace Monstrus::View