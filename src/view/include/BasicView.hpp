#pragma once

#include <memory>
#include <unordered_map>
#include "SDL.h"
#include "EntityTypes.hpp"
#include "IRenderable.hpp"
#include "Sprite.hpp"
#include "IView.hpp"

namespace Monstrus::View {
    class BasicView : public IView {
       public:
        ~BasicView();
        BasicView& operator=(const BasicView& other) = delete;
        BasicView(const BasicView& other) = delete;

        BasicView() { initAssets(); }

        void renderAll() override;

       private:
        /**
         * @brief Loads all images and spritesheets.
         *
         */
        void loadAssets();

        /**
         * @brief Initializes all assets.
         *
         */
        void initAssets();

        // Considering using smart pointers, but a hassle to deal with custom deletion
        // Main game display.
        SDL_Window* window;
        // Surface contained by the window
        SDL_Surface* display;
        // Renderer
        SDL_Renderer* renderer;
        // Window dimensions
        int width{1000};
        int height{500};

        // Entities and their sprites
        std::unique_ptr<std::unordered_map<Entities::EntityType, std::unique_ptr<IRenderable>>> entities{
            std::make_unique<std::unordered_map<Entities::EntityType, std::unique_ptr<IRenderable>>>()};
        // Assets such as backgrounds or other non-entities
        std::unique_ptr<std::unordered_map<Entities::EntityType, std::unique_ptr<IRenderable>>> assets{
            std::make_unique<std::unordered_map<Entities::EntityType, std::unique_ptr<IRenderable>>>()};
    };
}  // namespace Monstrus::View