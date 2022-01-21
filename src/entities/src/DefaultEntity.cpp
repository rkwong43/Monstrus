#include <iostream>
#include "DefaultEntity.hpp"

namespace Game::Entities {
    void Entity::setUp() { std::cout << "Setting up!" << std::endl; }
    void Entity::takeAction() { std::cout << "Taking action!" << std::endl; }
    void Entity::react() { std::cout << "Reacting!" << std::endl; }
}  // namespace Game::Entities