#include "BaseModel.hpp"
#include <iostream>
#include <stdexcept>

namespace Game::Model {
    void BaseModel::update() {
        // Actions that are performed each tick

        // TODO: have some sort of lock or blocker so animations can play out etc.
    }

    void BaseModel::setupPhase() {
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
        // Record what happened in a game state of some kind?
        allies->front()->takeAction();
        enemies->front()->takeAction();
        // Checks if either are alive
        // TODO: implement health
    }

    void BaseModel::reactionPhase() {
        // Find some way to pass down information about what happened (some kind of update or event? A gamestate?)
        for (auto& ally : *allies) {
            ally->react();
        }
        for (auto& enemy : *enemies) {
            enemy->react();
        }
    }
}  // namespace Game::Model