#include <iostream>
#include <stdexcept>
#include <memory>
#include "BaseModel.hpp"
#include "EntityTypes.hpp"
#include "Knight.hpp"

namespace Game::Model {
    void BaseModel::update() {
        // TODO: have some sort of lock or blocker so animations can play out etc.
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
        // More processing?
    }

    void BaseModel::checkCurrentSide() {
        if (currentIndex == currentSide->size() || currentSide->empty()) {
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
        checkCurrentSide();
        if (!gameOver) {
            currentSide->at(currentIndex)->setUp();
            currentIndex++;
        }
    }

    void BaseModel::actionPhase() {
        checkCurrentSide();
        // Handle all the other logic like taking damage, healing, buffs/debuffs etc.
        // Record what happened in a game state of some kind
        if (!gameOver) {
            currentSide->at(currentIndex)->takeAction();
            currentIndex++;
            // Have to find a way to check if the opposing side's front unit or any unit is dead
        }
        // Checks if either are alive
        // TODO: implement health
    }

    void BaseModel::reactionPhase() {
        // Find some way to pass down information about what happened (some kind of update or event? A gamestate?)
        checkCurrentSide();
        if (!gameOver) {
            // Check if unit is dead?
            currentSide->at(currentIndex)->react();
            currentIndex++;
        }
    }

    void BaseModel::generateUnits() {
        // TODO: Add generator object with a factory
        std::cout << "Generating units..." << std::endl;
        // TODO: For now, 2 for testing
        for (int i = 0; i < 2; ++i) {
            allies->push_back(std::make_unique<Entities::Knight>());
            enemies->push_back(std::make_unique<Entities::Knight>());
        }
        std::cout << "Done generating units!" << std::endl;
    }

    void BaseModel::updateState() {
        // Cycles through the states
        currentState = states->front();
        states->next();
    }
}  // namespace Game::Model