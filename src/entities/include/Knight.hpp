#pragma once

#include "DefaultEntity.hpp"
#include "EntityTypes.hpp"
#include "Action.hpp"

namespace Game::Entities {
    class Knight : public Entity {
       public:
        /**
         * @brief Creates a Knight with default attributes.
         *
         */
        Knight() : Entity(25, 15) {}

        const Action setUp() override;
        const Action takeAction() override;
        const Action react() override;

        EntityType getType() override { return EntityType::Knight; }
    };
}