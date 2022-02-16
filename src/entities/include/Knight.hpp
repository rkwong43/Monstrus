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

        Action setUp() override;
        Action takeAction() override;
        Action react() override;

        EntityType getType() override { return EntityType::Knight; }
    };
}