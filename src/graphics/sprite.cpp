#include "sgc/graphics/sprite.hpp"

sgc::graphics::Sprite::Sprite(std::shared_ptr<Tileset> tileset, tile::TilesetPosition2D gridPosition) :
    m_tileset(tileset)
{
    this->SetTilesetPosition(gridPosition);
}

void sgc::graphics::Sprite::SetTilesetPosition(tile::TilesetPosition2D gridPosition)
{
    m_tilesetPosition = static_cast<tile::TileId>(gridPosition.y * m_tileset->GetSizeInTiles().x + gridPosition.x);
}

void sgc::graphics::Sprite::SetTilesetPosition(tile::TileId tileId)
{
    m_tilesetPosition = tileId;
}

void sgc::graphics::Sprite::SetPositionPx(sgc::graphics::PixelPosition2D position)
{
    m_position = position;
}
void sgc::graphics::Sprite::Draw(const RenderContext& context)
{    
    if (!context.renderer) {
        return;
    }

    auto texture = m_tileset->GetTexture();

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, 255);

    SDL_FRect dstRect = {
        static_cast<float>(m_position.x),
        static_cast<float>(m_position.y),
        static_cast<float>(m_tileset->m_tileSize.x),
        static_cast<float>(m_tileset->m_tileSize.y)
    };

    SDL_FRect srcRect = m_tileset->GetTileRect(m_tilesetPosition);
    
    SDL_RenderTexture(context.renderer, texture, &srcRect, &dstRect);
}