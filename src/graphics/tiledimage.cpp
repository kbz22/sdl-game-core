#include "sgc/graphics/tiledimage.hpp"
#include "sgc/tile/tile.hpp"
#include "sgc/coordinates/screenworld.hpp"

sgc::graphics::TiledImage::TiledImage(std::shared_ptr<TiledLayer> layer) :
    m_layer(layer)
{
}

uint8_t sgc::graphics::TiledImage::GetAlpha() const
{
    return m_alpha;
}

void sgc::graphics::TiledImage::SetAlpha(uint8_t alpha)
{
    m_alpha = alpha;
}

void sgc::graphics::TiledImage::Draw(RenderContext const& context)
{
    if (!m_layer || !context.renderer) {
        return;
    }

    auto& tileset = m_layer->GetTileset();
    auto& tileStorage = m_layer->GetTileStorage();

    SDL_SetTextureBlendMode(tileset.GetTexture(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tileset.GetTexture(), m_alpha);

    const auto size_xy = tileset.GetSizeInTiles();
    const auto tileSize = tileset.GetTileSize();

    auto size_x = context.view.camera.w / size_xy.x;
    auto size_y = context.view.camera.h / size_xy.y;

    const auto& camera = context.view.camera;

    const auto startX = static_cast<sgc::math::ival>(
        std::floor(camera.x / tileSize.x)
    );

    const auto startY = static_cast<sgc::math::ival>(
        std::floor(camera.y / tileSize.y)
    );

    const auto endX = static_cast<sgc::math::ival>(
        std::ceil((camera.x + camera.w) / tileSize.x)
    );

    const auto endY = static_cast<sgc::math::ival>(
        std::ceil((camera.y + camera.h) / tileSize.y)
    );

    std::vector<sgc::tile::Tile> tileBuffer;

    tileStorage.GetTilesWithin(
        { startX, startY },
        { endX, endY },
        tileBuffer
    );

    for (const auto& tile : tileBuffer)
    {
        SDL_FRect srcRect = tileset.GetTileRect(tile.id);

        sgc::math::fvec2 worldPosition{
            static_cast<float>(tile.position.x) * tileSize.x,
            static_cast<float>(tile.position.y) * tileSize.y
        };

        auto screenPosition = sgc::coordinates::WorldToScreen(
            worldPosition,
            context.view
        );

        auto screenBottomRight = sgc::coordinates::WorldToScreen(
            {
                worldPosition.x + tileSize.x,
                worldPosition.y + tileSize.y
            },
            context.view
        );

        SDL_FRect dstRect{
            screenPosition.x,
            screenPosition.y,
            screenBottomRight.x - screenPosition.x,
            screenBottomRight.y - screenPosition.y
        };

        SDL_RenderTexture(
            context.renderer,
            tileset.GetTexture(),
            &srcRect,
            &dstRect
        );
    }

    /* for (sgc::math::ival y = startY; y < endY; ++y){
        for (sgc::math::ival x = startX; x < endX; ++x){

            sgc::tile::TilePosition2D gridPos{x, y};

            auto tileIdOpt = tileStorage.GetTileAt(gridPos);

            if (!tileIdOpt.has_value())
                continue;

            SDL_FRect srcRect = tileset.GetTileRect(tileIdOpt.value());
            
            sgc::math::fvec2 worldPosition{
                static_cast<float>(x * tileSize.x),
                static_cast<float>(y * tileSize.y)
            };

            auto screenPosition = sgc::coordinates::WorldToScreen(
                worldPosition,
                context.view
            );

            auto screenBottomRight = sgc::coordinates::WorldToScreen({
                worldPosition.x + tileSize.x,
                worldPosition.y + tileSize.y
                },
                context.view
            );

            SDL_FRect dstRect{
                screenPosition.x,
                screenPosition.y,
                screenBottomRight.x - screenPosition.x,
                screenBottomRight.y - screenPosition.y
            };

            SDL_RenderTexture(
                context.renderer,
                tileset.GetTexture(),
                &srcRect,
                &dstRect
            );
        }
    } */
}