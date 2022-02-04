#pragma once

namespace Game::Model {
    class IModel {
       public:
        /**
         * @brief Updates the game elements, to be called every tick
         *
         * If necessary, some blocks should be added to allow for animation times or pauses for better flow.
         *
         */
        virtual void update() = 0;

        /**
         * @brief Returns if the game is over.
         *
         * @return True if the game is over, false otherwise
         */
        virtual bool isGameOver() = 0;
    };
}  // namespace Game::Model