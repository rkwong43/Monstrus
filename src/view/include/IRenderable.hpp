#pragma once

#include "SDL.h"

namespace Monstrus::View {
    /**
     * @brief Represents something that can be rendered and displayed.
     *
     */
    class IRenderable {
       public:
        virtual ~IRenderable() {}
        /**
         * @brief Returns the image to render on the screen.
         *
         */
        virtual SDL_Surface* getImage() = 0;

        /**
         * @brief Animates the object by changing what image is rendered.
         *
         */
        virtual void animate() = 0;
    };
}  // namespace Monstrus::View