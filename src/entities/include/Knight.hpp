#pragma once

#include "DefaultEntity.hpp"
#include "EntityTypes.hpp"

namespace Game::Entities {
    class Knight : public Entity {
       public:
        /**
         * @brief Creates a Knight with default attributes.
         *
         */
        Knight() : Entity(25, 15) {}

        void setUp() override;
        void takeAction() override;
        void react() override;

        EntityType getType() override { return EntityType::Knight; }
    };
}