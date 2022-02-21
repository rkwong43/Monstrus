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
        Sprite& operator=(const Sprite& other) = default;
        Sprite(const Sprite& other) = default;

        Sprite(std::initializer_list<SDL_Surface*> images) { sprites = std::make_unique<Utils::ConstLinkedList<SDL_Surface*>>(images); }

        SDL_Surface* getImage() override;
        void animate() override;

       private:
        // Sprites/images to cycle through or display
        std::unique_ptr<Utils::ConstLinkedList<SDL_Surface*>> sprites;
    };
}  // namespace Monstrus::View