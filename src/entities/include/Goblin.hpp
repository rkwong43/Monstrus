#pragma once

#include "DefaultEntity.hpp"
#include "EntityTypes.hpp"
#include "Action.hpp"

namespace Monstrus::Entities {
    class Goblin : public Entity {
       public:
        /**
         * @brief Creates a Knight with default attributes.
         *
         */
        Goblin() : Entity(15, 10) {}

        const Action setUp() override;
        const Action takeAction() override;
        const Action react() override;

        EntityType getType() override { return EntityType::Goblin; }
    };
}