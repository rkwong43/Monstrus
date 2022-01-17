#pragma once

namespace Game::View {
    class IView {
       public:
        /**
         * @brief Renders the game and all the elements shown to the player
         *
         */
        virtual void render() = 0;
        /**
         * @brief Initializes and loads all images and assets into memory
         *
         */
        virtual void initAssets() = 0;
    };
}  // namespace Game::View