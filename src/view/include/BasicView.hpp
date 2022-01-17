#pragma once

#include "IView.hpp"

namespace Game::View {
    class BasicView : public IView {
       public:
        void render() override;
        void initAssets() override;
    };
}  // namespace Game::View