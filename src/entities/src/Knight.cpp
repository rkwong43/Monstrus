#include <iostream>
#include <string>
#include "Knight.hpp"

namespace Game::Entities {
    void Knight::setUp() { std::cout << "Knight is setting up! Current HP is " + std::to_string(this->hp) << std::endl; }
    void Knight::takeAction() {
        std::cout << "Knight: Action time! Reducing HP by 1." << std::endl;
        this->hp -= 1;
    }
    void Knight::react() { std::cout << "Knight: Reacting! Current HP is " + std::to_string(this->hp) << std::endl; }
}