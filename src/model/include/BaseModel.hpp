#pragma once

#include <vector>
#include <list>
#include <memory>

#include "IModel.hpp"
#include "IEntity.hpp"

namespace Game::Model {
    class BaseModel : public IModel {
       public:
        // TODO: Maybe add some parameters later on
        BaseModel() { generateUnits(); }

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
        /**
         * @brief States representing the phases of the state machine the model will go through.
         *
         */
        enum struct State { SetupAlly, SetupEnemy, ActionAlly, ActionEnemy, ReactionAlly, ReactionEnemy };

        /**
         * @brief Generates a starting team of units and sets up the types of units generated in the run.
         *
         * TODO: Attach a generator class? Or a factory
         *
         */
        void generateUnits();

        /**
         * @brief Updates the state of the model to the next.
         *
         */
        void updateState();

        // Current state of the model
        State currentState{State::SetupAlly};

        // Linked list representing the state machine
        std::unique_ptr<std::list<State>> states{std::make_unique<std::list<State>>(State::SetupAlly, State::SetupEnemy, State::ActionAlly,
                                                                                    State::ActionEnemy, State::ReactionAlly, State::ReactionEnemy)};

        // Should be limited to 5(?) units for now
        // Replace with a linked list?
        // TODO: Look into some other way of storing them other than nested unique pointers. This is very messy
        // Look into efficiency, but shouldn't be too big of an issue because these aren't meant to be large vectors
        std::unique_ptr<std::vector<std::unique_ptr<Entities::IEntity>>> allies{std::make_unique<std::vector<std::unique_ptr<Entities::IEntity>>>()};
        std::unique_ptr<std::vector<std::unique_ptr<Entities::IEntity>>> enemies{std::make_unique<std::vector<std::unique_ptr<Entities::IEntity>>>()};
    };
}  // namespace Game::Model