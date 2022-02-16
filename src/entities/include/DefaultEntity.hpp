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

        virtual const Action setUp() = 0;
        virtual const Action takeAction() = 0;
        virtual const Action react() = 0;
        int getHp() override;
        void update(Update update) override;

        virtual EntityType getType() = 0;

       protected:
        // Hitpoints of the entity, dies when it hits 0
        int hp;
        // Attack damage of the entity
        int attack;
        // Current position on team
        int posn;
        // Size of team
        int teamSize;
        // Size of enemy team
        int enemySize;
    };
}  // namespace Game::Entities