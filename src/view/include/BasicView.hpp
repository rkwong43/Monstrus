#pragma once

#include "IView.hpp"

namespace Monstrus::View {
    class BasicView : public IView {
       public:
        void renderAll() override;
        void initAssets() override;
    };
}  // namespace Monstrus::View