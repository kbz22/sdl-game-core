#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/tileset.hpp"
#include "sgc/types.hpp"

#include <memory>

namespace sgc::graphics {

    class Sprite : public IDrawable {
        private:            
            std::shared_ptr<Tileset> m_tileset;
            math::vec2 m_position{ 0, 0 };            
            math::uvec2 m_gridPosition{ 0, 0 };
            SDL_Renderer *m_renderer = nullptr;        

        public:
            Sprite(std::shared_ptr<Tileset> tileset, math::uvec2 gridPosition);            

            void SetTilesetPosition(math::uvec2 gridPosition);
            void SetPositionPx(math::vec2 position);

            void Draw() override;
            void SetRenderer(SDL_Renderer *renderer) override;
    };

}