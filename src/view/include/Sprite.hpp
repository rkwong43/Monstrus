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
        ~Sprite();
        Sprite& operator=(const Sprite& other) = delete;
        Sprite(const Sprite& other) = delete;

        Sprite(std::initializer_list<SDL_Surface*> images) { sprites = std::make_unique<Utils::ConstLinkedList<SDL_Surface*>>(images); }

        void render() override;
        void animate() override;

       private:
        std::unique_ptr<Utils::ConstLinkedList<SDL_Surface*>> sprites;
    };
}  // namespace Monstrus::View