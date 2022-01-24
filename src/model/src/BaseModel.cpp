#include <iostream>
#include <stdexcept>
#include <memory>
#include "BaseModel.hpp"
#include "EntityTypes.hpp"
#include "Knight.hpp"

namespace Game::Model {
    void BaseModel::update() {
        // Actions that are performed each tick
        // TODO: have some sort of lock or blocker so animations can play out etc.
        // TODO: Add support for enemy phases
        switch (currentState) {
            case State::SetupAlly:
                setupPhase();
                break;
            case State::ActionAlly:
                actionPhase();
                break;
            case State::ReactionAlly:
                reactionPhase();
                break;
            default:
                throw std::runtime_error("Invalid state encountered in model state machine.");
                break;
        }
        // Check if each phase is done:
        if (true) {
            updateState();
        }
    }

    void BaseModel::setupPhase() {
        // TODO: Break into individual steps later on for animations
        for (auto& ally : *allies) {
            ally->setUp();
        }
        for (auto& enemy : *enemies) {
            enemy->setUp();
        }
    }

    void BaseModel::actionPhase() {
        // Only uses first elements of each
        // Both allies and enemies should be non-empty
        if (allies->empty() || enemies->empty()) {
            throw std::runtime_error("Cannot execute action phase if one of the two parties are empty.");
        }
        // Handle all the other logic like taking damage, healing, buffs/debuffs etc.
        // Record what happened in a game state of some kind
        allies->front()->takeAction();
        enemies->front()->takeAction();
        // Checks if either are alive
        // TODO: implement health
    }

    void BaseModel::reactionPhase() {
        // TODO: Break into individual steps later on for animations
        // Find some way to pass down information about what happened (some kind of update or event? A gamestate?)
        for (auto& ally : *allies) {
            ally->react();
        }
        for (auto& enemy : *enemies) {
            enemy->react();
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
        auto oldState = states->front();
        states->pop_front();
        currentState = states->front();
        states->push_back(currentState);
    }
}  // namespace Game::Model