#include <iostream>
#include "DefaultEntity.hpp"

namespace Game::Entities {
    Action Entity::setUp() { std::cout << "Setting up!" << std::endl; }
    Action Entity::takeAction() { std::cout << "Taking action!" << std::endl; }
    Action Entity::react() { std::cout << "Reacting!" << std::endl; }
    int Entity::getHp() { return hp; }
}  // namespace Game::Entities