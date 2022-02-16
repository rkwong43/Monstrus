#include <iostream>
#include <string>
#include "Goblin.hpp"

namespace Game::Entities {
    const Action Goblin::setUp() {
        // For now, reduces attack of opposite enemy
        std::cout << "Goblin is setting up! Current HP is " + std::to_string(this->hp) << std::endl;
        return Action(ActionType::DEBUFF, 5, Side::ENEMIES, {posn});
    }
    const Action Goblin::takeAction() {
        // Attacks frontmost enemy
        std::cout << "Goblin: Action time!" << std::endl;
        return Action(ActionType::ATTACK, attack, Side::ENEMIES, {0});
    }
    const Action Goblin::react() {
        // Increases own HP by 2
        std::cout << "Goblin: Reacting! Current HP is " + std::to_string(this->hp) << std::endl;
        return Action(ActionType::BUFF, 2, Side::ALLIES, {posn});
    }
}