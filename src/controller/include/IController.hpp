#pragma once

namespace Game::Controller {
    class IController {
       public:
        /**
         * @brief Starts an instance of the game
         *
         * Includes the main game loop and processes inputs. Will also manage communication between the model and view.
         */
        virtual void start() = 0;
    };
}  // Gam::Controller::IController