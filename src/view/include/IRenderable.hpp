#pragma once

namespace Monstrus::View {
    /**
     * @brief Represents something that can be rendered and displayed.
     *
     */
    class IRenderable {
       public:
        virtual ~IRenderable() {}
        /**
         * @brief Renders the object on the screen.
         *
         */
        virtual void render() = 0;

        /**
         * @brief Animates the object by changing what image is rendered.
         *
         */
        virtual void animate() = 0;

        /**
         * @brief Destroys the images loaded through SDL.
         *
         */
        virtual void destroy() = 0;
    };
}  // namespace Monstrus::View