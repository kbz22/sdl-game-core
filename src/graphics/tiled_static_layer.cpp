#include "sgc/graphics/tiled_static_layer.hpp"

sgc::graphics::TiledStaticLayer::TiledStaticLayer(
    std::shared_ptr<Tileset> &tileset,
    std::vector<sgc::math::uvec2> tilePositions,
    sgc::math::uvec2 size,
    sgc::math::vec2 position) 
    :
    m_tileset(tileset),
    m_tilePositions(std::move(tilePositions)),
    m_size(size),
    m_position(position)
{}

void sgc::graphics::TiledStaticLayer::SetPositionPx(sgc::math::vec2 position)
{
    m_position = position;
}

void sgc::graphics::TiledStaticLayer::SetRenderer(SDL_Renderer *renderer)
{
    m_renderer = renderer;
}

void sgc::graphics::TiledStaticLayer::Draw()
{
    if (!m_renderer) {
        return;
    }

    auto texture = m_tileset->GetTexture();

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, 255);

    const sgc::math::uvec2 tileSize = m_tileset->GetTileSize();

    for (uint64_t row = 0; row < m_size.y; ++row) {
        for (uint64_t col = 0; col < m_size.x; ++col) {
            const sgc::math::uvec2 tilePos = m_tilePositions[row * m_size.x + col];
            const SDL_FRect srcRect = m_tileset->GetTileRect(tilePos);
            const SDL_FRect dstRect = {
                static_cast<float>(m_position.x + static_cast<int64_t>(col * tileSize.x)),
                static_cast<float>(m_position.y + static_cast<int64_t>(row * tileSize.y)),
                static_cast<float>(tileSize.x),
                static_cast<float>(tileSize.y)
            };
            SDL_RenderTexture(m_renderer, texture, &srcRect, &dstRect);
        }
    }
}
