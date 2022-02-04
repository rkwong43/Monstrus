#pragma once

#include <vector>
#include <list>
#include <memory>

#include "IModel.hpp"
#include "IEntity.hpp"
#include "LinkedList.hpp"

// TODO: Look for a better way to do this
// Mainly have this to improve readability
#define ENTITY_VECTOR_TYPE std::shared_ptr<std::vector<std::unique_ptr<Entities::IEntity>>>

namespace Game::Model {
    class BaseModel : public IModel {
       public:
        // TODO: Maybe add some parameters later on
        BaseModel() { generateUnits(); }

        void update() override;

        bool isGameOver() override;

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
        enum struct State { Setup, Action, Reaction };

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

        /**
         * @brief Checks the current side to see if empty or index out of range. Cycles to the next side if it is.
         *
         */
        void checkCurrentSide();

        // If the game is over!
        bool gameOver{false};
        // If the state needs to be cycled:
        // Acts sort of like a switch
        // Might need to change this if I ever allow multiple sides/teams.
        bool changeState{false};

        // Current state of the model
        State currentState{State::Setup};

        // Linked list representing the state machine
        std::unique_ptr<Utils::ConstLinkedList<State>> states{
            std::make_unique<Utils::ConstLinkedList<State>>(std::initializer_list<State>({State::Setup, State::Action, State::Reaction}))};

        // Should be limited to 5(?) units for now
        // Replace with a linked list?
        // TODO: Look into some other way of storing them other than nested unique pointers. This is very messy
        // Look into efficiency, but shouldn't be too big of an issue because these aren't meant to be large vectors
        ENTITY_VECTOR_TYPE allies{std::make_shared<std::vector<std::unique_ptr<Entities::IEntity>>>()};
        ENTITY_VECTOR_TYPE enemies{std::make_shared<std::vector<std::unique_ptr<Entities::IEntity>>>()};

        std::unique_ptr<Utils::ConstLinkedList<ENTITY_VECTOR_TYPE>> entities{
            std::make_unique<Utils::ConstLinkedList<ENTITY_VECTOR_TYPE>>(std::initializer_list<ENTITY_VECTOR_TYPE>({allies, enemies}))};

        ENTITY_VECTOR_TYPE currentSide{entities->front()};
        // Index of the current side:
        int currentIndex{0};
    };
}  // namespace Game::Model