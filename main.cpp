#include <iostream>
#include <memory>

#include "SDL.h"
#include "IController.hpp"
#include "BasicController.hpp"

int main(int argc, char* argv[]) {
    std::unique_ptr<Game::Model::IModel> model = std::make_unique<Game::Model::BaseModel>();
    std::unique_ptr<Game::View::IView> view = std::make_unique<Game::View::BasicView>();
    std::unique_ptr<Game::Controller::IController> controller =
        std::make_unique<Game::Controller::BasicController>(std::move(model), std::move(view));
    controller->start();
    std::cout << "Hello world!" << std::endl;
    return 0;
}