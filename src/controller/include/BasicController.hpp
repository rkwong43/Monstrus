#pragma once

#include <memory>

#include "IController.hpp"
#include "IView.hpp"
#include "IModel.hpp"
#include "BaseModel.hpp"
#include "BasicView.hpp"

namespace Game::Controller {
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
        void processInput();

       private:
        // Model for game logic
        std::unique_ptr<Model::IModel> model;
        // View for rendering
        std::unique_ptr<View::IView> view;
    };
}  // namespace Game::Controller