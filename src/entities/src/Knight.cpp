#include <iostream>
#include <string>
#include "Knight.hpp"

namespace Monstrus::Entities {
    const Action Knight::setUp() {
        // For testing, increases HP by 2
        std::cout << "Knight is setting up! Current HP is " + std::to_string(this->hp) << std::endl;
        return Action(ActionType::BUFF, 2, Side::CURRENT, {posn});
    }
    const Action Knight::takeAction() {
        // Attacks frontmost unit for its attack damage
        std::cout << "Knight: Action time!" << std::endl;
        return Action(ActionType::ATTACK, attack, Side::OPPOSITE, {0});
    }
    const Action Knight::react() {
        // For now, just increase Attack by 3
        std::cout << "Knight: Reacting! Current HP is " + std::to_string(this->hp) << std::endl;
        return Action(ActionType::BUFF, 3, Side::CURRENT, {posn});
    }
}