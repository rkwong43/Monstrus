#include <iostream>
#include <memory>

#include "SDL.h"
#include "IController.hpp"
#include "BasicController.hpp"

int main(int argc, char* argv[]) {
    auto model = std::make_unique<Monstrus::Model::BaseModel>();
    auto view = std::make_unique<Monstrus::View::BasicView>();
    auto controller = std::make_unique<Monstrus::Controller::BasicController>(std::move(model), std::move(view));
    // Until rendering is complete, just going to do some stdout messages
    controller->start();
    std::cout << "Done!" << std::endl;
    return 0;
}