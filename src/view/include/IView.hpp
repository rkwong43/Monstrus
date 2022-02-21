#pragma once

namespace Monstrus::View {
    class IView {
       public:
        virtual ~IView() {}
        /**
         * @brief Renders the game and all the elements shown to the player.
         *
         */
        virtual void renderAll() = 0;
        // TODO: Add some way to handle animations
    };
}  // namespace Monstrus::View