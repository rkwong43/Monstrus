#pragma once
#include <stdlib.h>

#include "IEntity.hpp"

namespace Game::Entities {
    class DefaultEntity : public IEntity {
       public:
        void setUp() override;
        void takeAction() override;
        void react() override;
    };
}  // namespace Game::Entities