#include <iostream>
#include <stdexcept>
#include <memory>
#include "BaseModel.hpp"
#include "EntityTypes.hpp"
#include "Knight.hpp"
#include "Goblin.hpp"

namespace Game::Model {
    void BaseModel::update() {
        // TODO: have some sort of lock or blocker so animations can play out etc.
        checkCurrentSide();
        if (gameOver) {
            std::cout << "Game is over!" << std::endl;
            return;
        }
        switch (currentState) {
            case State::Setup:
                setupPhase();
                break;
            case State::Action:
                actionPhase();
                break;
            case State::Reaction:
                reactionPhase();
                break;
            default:
                throw std::runtime_error("Invalid state encountered in model state machine.");
        }
        // TODO: Maybe send out a game update to the view if things change?
        removeIfDead(allies);
        removeIfDead(enemies);
        // More processing?
    }

    void BaseModel::checkCurrentSide() {
        if (currentIndex == currentSide->size() || currentSide->empty()) {
            if (changeState) {
                updateState();
            }
            changeState = !changeState;
            // Cycles to the next group
            currentIndex = 0;
            entities->next();
            currentSide = entities->front();
            // If the new side is empty as well, game is over
            if (currentSide->empty()) {
                gameOver = true;
            }
        }
    }

    void BaseModel::setupPhase() {
        // Sets up the current entity:
        currentSide->at(currentIndex)->setUp();
        currentIndex++;
    }

    void BaseModel::actionPhase() {
        // Handle all the other logic like taking damage, healing, buffs/debuffs etc.
        // Record what happened in a game state of some kind
        currentSide->front()->takeAction();
        // Forces a side change and/or a state change
        currentIndex = currentSide->size();
        // Have to find a way to check if the opposing side's front unit or any unit is dead
        // Checks if either are alive
        // TODO: implement health
    }

    void BaseModel::reactionPhase() {
        // Find some way to pass down information about what happened (some kind of update or event? A gamestate?)
        // Check if unit is dead?
        currentSide->at(currentIndex)->react();
        currentIndex++;
    }

    void BaseModel::generateUnits() {
        // TODO: Add generator object with a factory
        std::cout << "Generating units..." << std::endl;
        // TODO: For now, 1 for testing
        for (int i = 0; i < 1; ++i) {
            allies->push_back(std::make_unique<Entities::Knight>());
            enemies->push_back(std::make_unique<Entities::Goblin>());
        }
        std::cout << "Done generating units!" << std::endl;
    }

    void BaseModel::updateState() {
        std::cout << "Changing state!" << std::endl;
        // Cycles through the states
        states->next();
        currentState = states->front();
    }

    const bool BaseModel::isGameOver() {
        // Might want to add more logic here in the future
        return gameOver;
    }

    void BaseModel::removeIfDead(ENTITY_VECTOR_TYPE & vec) {
        vec->erase(std::remove_if(vec->begin(), vec->end(), [](std::unique_ptr<Entities::IEntity> e) { return e->getHp() <= 0; }));
    }
}  // namespace Game::Model