#include <iostream>
#include "DefaultEntity.hpp"

namespace Monstrus::Entities {
    int Entity::getHp() { return hp; }
    void Entity::update(Update update) {
        // Reminder: teamSize and enemySize is the size of the vector
        posn = update.posn;
        teamSize = update.teamNum;
        enemySize = update.enemyNum;
    }
}  // namespace Monstrus::Entities