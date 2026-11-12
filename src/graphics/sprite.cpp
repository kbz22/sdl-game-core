#include "sgc/graphics/sprite.hpp"
#include "sgc/coordinates/screenworld.hpp"

sgc::graphics::Sprite::Sprite(std::shared_ptr<Tileset> tileset, tile::TilePosition2D gridPosition) :
    m_tileset(tileset)
{
    this->SetTilesetPosition(gridPosition);
}

void sgc::graphics::Sprite::SetTilesetPosition(tile::TilePosition2D gridPosition)
{
    m_tilesetPosition = static_cast<tile::TileId>(
        gridPosition.y * m_tileset->GetSizeInTiles().x + gridPosition.x
    );
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

    sgc::math::fvec2 worldPosition{
        static_cast<float>(m_position.x),
        static_cast<float>(m_position.y)
    };

    auto screenPosition = sgc::coordinates::ToScreen(
        worldPosition,
        context.view
    );

    auto screenBottomRight = sgc::coordinates::ToScreen({
            worldPosition.x + m_tileset->m_tileSize.x,
            worldPosition.y + m_tileset->m_tileSize.y
        },
        context.view
    );

    SDL_FRect dstRect{
        screenPosition.x,
        screenPosition.y,
        screenBottomRight.x - screenPosition.x,
        screenBottomRight.y - screenPosition.y
    };

    SDL_FRect srcRect =  m_tileset->GetTileRect(m_tilesetPosition);
    
    SDL_RenderTexture(
        context.renderer,
        texture,
        &srcRect,
        &dstRect
    );
}