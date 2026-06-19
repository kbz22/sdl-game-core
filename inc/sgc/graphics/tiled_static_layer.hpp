#pragma once

#include "sgc/graphics/tileset.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/types.hpp"

#include <memory>
#include <vector>

namespace sgc::graphics {

    class TiledStaticLayer : public IDrawable {

     private:
        std::shared_ptr<Tileset> m_tileset;
        std::vector<math::uvec2> m_tilePositions;
        math::uvec2 m_size{ 0, 0 };
        math::vec2 m_position{ 0, 0 };

     public:
          TiledStaticLayer(
            std::shared_ptr<Tileset> &tileset,
            std::vector<math::uvec2> tilePositions,
            math::uvec2 size,
            math::vec2 position = { 0, 0 }
        );

          void SetPositionPx(math::vec2 position);
          void Draw(const RenderContext& context) override;

    };

}