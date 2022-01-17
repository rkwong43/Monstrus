#pragma once

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
    };
}  // namespace Game::Entities