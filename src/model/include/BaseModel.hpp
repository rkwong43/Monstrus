#pragma once

#include <vector>
#include <memory>

#include "IModel.hpp"
#include "IEntity.hpp"

namespace Game::Model {
    class BaseModel : public IModel {
       public:
        void update() override;

       protected:
        /**
         * @brief Performs the actions of the entities in the setup phase
         *
         * Iterates through each side and performs the setup phase ability of each unit.
         *
         */
        void setupPhase();
        /**
         * @brief Makes the frontmost unit of each side begin their action.
         *
         * After the setup phase, each unit at the front of each party take their actions (attack each other).
         *
         */
        void actionPhase();
        /**
         * @brief Each unit of both sides react to the action phase.
         *
         * If applicable, each unit performs their reaction ability.
         *
         */
        void reactionPhase();

       private:
        // Should be limited to 5(?) units for now
        std::unique_ptr<std::vector<std::unique_ptr<Game::Entities::IEntity>>> allies;
        std::unique_ptr<std::vector<std::unique_ptr<Game::Entities::IEntity>>> enemies;
    };
}  // namespace Game::Model