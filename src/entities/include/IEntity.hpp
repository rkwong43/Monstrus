#pragma once

#include "EntityTypes.hpp"

namespace Game::Entities {
    class IEntity {
       public:
        /**
         * @brief Calls any abilities that apply in the setup phase (first phase)
         *
         * Called in the setup phase, even if it is not the entity's turn for action.
         */
        virtual void setUp() = 0;
        /**
         * @brief Calls any abilities that apply in the action phase (second phase)
         *
         * Called in the action phase, where this entity is the frontmost entity.
         */
        virtual void takeAction() = 0;
        /**
         * @brief Calls any abilities that apply in the reaction phase (third phase)
         *
         * Called in the reaction phase, after the frontmost entities use their actions.
         */
        virtual void react() = 0;
        /**
         * @brief Returns what type the entity is.
         *
         * @return EntityType of what type of entity it is.
         */
        virtual EntityType getType() = 0;
        /**
         * @brief Returns the entity's current HP
         *
         */
        virtual int getHp() = 0;
    };
}  // namespace Game::Entities