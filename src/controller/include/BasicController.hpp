#pragma once

#include <memory>

#include "SDL.h"
#include "IController.hpp"
#include "IView.hpp"
#include "IModel.hpp"
#include "BaseModel.hpp"
#include "BasicView.hpp"

namespace Monstrus::Controller {
    class BasicController : public IController {
       public:
        /**
         * @brief Construct a new Basic Controller object
         *
         * @param m A Model for the controller to take ownership of
         * @param v A View for the controller to take ownership of
         */
        BasicController(std::unique_ptr<Model::IModel> m, std::unique_ptr<View::IView> v) {
            model = std::move(m);
            view = std::move(v);
        }
        void start() override;

       protected:
        /**
         * @brief Processes user input and SDL events.
         *
         * @param e SDL event handler
         * @return true if user quit out of program
         * @return false to continue running per usual
         */
        bool processInput(SDL_Event* e);

       private:
        // Model for game logic
        std::unique_ptr<Model::IModel> model;
        // View for rendering
        std::unique_ptr<View::IView> view;
    };
}  // namespace Monstrus::Controller