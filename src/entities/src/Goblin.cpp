#include <iostream>
#include <string>
#include "Goblin.hpp"

namespace Game::Entities {
    Action Goblin::setUp() { std::cout << "Goblin is setting up! Current HP is " + std::to_string(this->hp) << std::endl; }
    Action Goblin::takeAction() {
        std::cout << "Goblin: Action time! Reducing HP by 1." << std::endl;
        this->hp -= 1;
    }
    Action Goblin::react() { std::cout << "Goblin: Reacting! Current HP is " + std::to_string(this->hp) << std::endl; }
}