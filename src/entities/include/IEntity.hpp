#pragma once

#include "EntityTypes.hpp"
#include "Action.hpp"

namespace Monstrus::Entities {
    /**
     * @brief Represents an update to an entity.
     *
     * Can be expanded if necessary.
     */
    struct Update {
        Update(int posn, int teamNum, int enemyNum) : posn(posn), teamNum(teamNum), enemyNum(enemyNum) {}
        // Current position in the party
        int posn;
        // Number of teammates (includes self)
        int teamNum;
        // Number of enemies on the opposite self
        int enemyNum;
    };

    class IEntity {
       public:
        /**
         * @brief Calls any abilities that apply in the setup phase (first phase)
         *
         * Called in the setup phase, even if it is not the entity's turn for action.
         */
        virtual const Action setUp() = 0;
        /**
         * @brief Calls any abilities that apply in the action phase (second phase)
         *
         * Called in the action phase, where this entity is the frontmost entity.
         */
        virtual const Action takeAction() = 0;
        /**
         * @brief Calls any abilities that apply in the reaction phase (third phase)
         *
         * Called in the reaction phase, after the frontmost entities use their actions.
         */
        virtual const Action react() = 0;
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
        /**
         * @brief Adds the given number to the entity's HP.
         *
         * @param num The number to change it by, can be negative or positive.
         *
         */
        virtual void addHp(const int num) = 0;
        /**
         * @brief Adds the given number to the entity's attack.
         *
         * @param num The number to change it by, can be negative or positive.
         *
         */
        virtual void addAttack(const int num) = 0;
        /**
         * @brief Updates the entity with necessary information to perform actions.
         *
         * @param update The information to take in.
         *
         */
        virtual void update(Update update) = 0;
    };
}  // namespace Monstrus::Entities