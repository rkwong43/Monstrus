#pragma once
#include <stdlib.h>
#include <memory>

#include "EntityTypes.hpp"
#include "Action.hpp"
#include "IEntity.hpp"

namespace Game::Entities {
    class Entity : public IEntity {
       public:
        /**
         * @brief Default constructor for a default entity. Sets all values to 10.
         *
         */
        Entity() : hp(10), attack(10){};

        /**
         * @brief Constructor for a default entity.
         *
         * @param hp The hit points of the entity
         * @param attack The attack stat of the entity
         */
        Entity(int hp, int attack) : hp(hp), attack(attack){};

        Action setUp() override;
        Action takeAction() override;
        Action react() override;
        int getHp() override;

        virtual EntityType getType() = 0;

       protected:
        // Hitpoints of the entity, dies when it hits 0
        int hp;
        // Attack damage of the entity
        int attack;
    };
}  // namespace Game::Entities