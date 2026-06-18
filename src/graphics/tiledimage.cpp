#include "sgc/graphics/tiledimage.hpp"

sgc::graphics::TiledImage::TiledImage(std::shared_ptr<TiledLayer> layer, SDL_Renderer *renderer) :
    m_layer(layer)
{
}

void sgc::graphics::TiledImage::Draw(RenderContext const& context)
{
    if (!m_layer || !context.renderer) {
        return;
    }

    auto& tileset = m_layer->GetTileset();
    auto& tileContainer = m_layer->GetTileContainer();

    SDL_SetTextureBlendMode(tileset.GetTexture(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tileset.GetTexture(), 255);

    const sgc::math::uvec2 tileSize = tileset.GetTileSize();

    
}
