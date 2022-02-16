#include <iostream>
#include <stdexcept>
#include <memory>
#include <functional>

#include "BaseModel.hpp"
#include "EntityTypes.hpp"
#include "IEntity.hpp"
#include "Knight.hpp"
#include "Goblin.hpp"

namespace Monstrus::Model {
    void BaseModel::update() {
        // TODO: have some sort of lock or blocker so animations can play out etc.
        if (gameOver) {
            std::cout << "Game is over!" << std::endl;
            return;
        }
        checkCurrentSide();
        updateEntities();
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
        applyAction(currentSide->at(currentIndex)->setUp());
        currentIndex++;
    }

    void BaseModel::actionPhase() {
        // Handle all the other logic like taking damage, healing, buffs/debuffs etc.
        // Record what happened in a game state of some kind
        applyAction(currentSide->front()->takeAction());
        // Forces a side change and/or a state change
        currentIndex = currentSide->size();
    }

    void BaseModel::reactionPhase() {
        // Find some way to pass down information about what happened (some kind of update or event? A gamestate?)
        // Check if unit is dead?
        // TODO: Pass an Action
        applyAction(currentSide->at(currentIndex)->react());
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

    void BaseModel::removeIfDead(ENTITY_VECTOR_PTR_TYPE & vec) {
        vec->erase(std::remove_if(vec->begin(), vec->end(), [&](const auto& e) { return e->getHp() <= 0; }), vec->end());
    }

    void BaseModel::updateEntities() {
        auto i = 0;
        auto allySize = allies->size();
        auto enemySize = enemies->size();
        for (auto& ally : *allies) {
            ally->update(Entities::Update(i, allySize, enemySize));
            i++;
        }
        i = 0;
        for (auto& enemy : *enemies) {
            enemy->update(Entities::Update(i, allySize, enemySize));
            i++;
        }
    }

    void BaseModel::applyAction(const Entities::Action action) {
        switch (action.side) {
            case Entities::Side::CURRENT:
                applyActionToSide(currentSide, action);
                break;
            case Entities::Side::OPPOSITE:
                // Lowkey pretty hacky but it works for now
                entities->next();
                applyActionToSide(entities->front(), action);
                entities->next();
                break;
            case Entities::Side::ALL:
                applyActionToSide(allies, action);
                applyActionToSide(enemies, action);
                break;
            default:
                throw std::runtime_error("Invalid team given as target");
        }
    }

    void BaseModel::applyActionToSide(const ENTITY_VECTOR_PTR_TYPE& side, const Entities::Action action) {
        auto val = action.value;
        std::function<void(Entities::IEntity*, int)> fn;
        switch (action.type) {
            case Entities::ActionType::ATTACK:
                val *= -1;
            case Entities::ActionType::DEFEND:
                fn = [=](Entities::IEntity* e, int n) { e->addHp(n); };
                break;
            case Entities::ActionType::DEBUFF:
                val *= -1;
            case Entities::ActionType::BUFF:
                fn = [=](Entities::IEntity* e, int n) { e->addAttack(n); };
                break;
            case Entities::ActionType::NONE:
                // TODO: Might want to add something here, like an animation?
                return;
                break;
            default:
                throw std::runtime_error("Unhandled action type!");
        }

        if (!action.targets.empty()) {
            for (auto i : action.targets) {
                fn(side->at(i).get(), val);
            }
        } else {
            for (auto& entity : *side) {
                fn(entity.get(), val);
            }
        }
    }

}  // namespace Monstrus::Model