#pragma once

#include "DefaultEntity.hpp"
#include "EntityTypes.hpp"
#include "Action.hpp"

namespace Game::Entities {
    class Goblin : public Entity {
       public:
        /**
         * @brief Creates a Knight with default attributes.
         *
         */
        Goblin() : Entity(15, 10) {}

        Action setUp() override;
        Action takeAction() override;
        Action react() override;

        EntityType getType() override { return EntityType::Goblin; }
    };
}