#pragma once

#include "DefaultEntity.hpp"
#include "EntityTypes.hpp"

namespace Game::Entities {
    class Goblin : public Entity {
       public:
        /**
         * @brief Creates a Knight with default attributes.
         *
         */
        Goblin() : Entity(15, 10) {}

        void setUp() override;
        void takeAction() override;
        void react() override;

        EntityType getType() override { return EntityType::Goblin; }
    };
}