#include "sgc/graphics/tiledimage.hpp"
#include "sgc/tile/tile.hpp"

sgc::graphics::TiledImage::TiledImage(std::shared_ptr<TiledLayer> layer) :
    m_layer(layer)
{
}

void sgc::graphics::TiledImage::Draw(RenderContext const& context)
{
    if (!m_layer || !context.renderer) {
        return;
    }

    auto& tileset = m_layer->GetTileset();
    auto& tileStorage = m_layer->GetTileStorage();

    SDL_SetTextureBlendMode(tileset.GetTexture(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tileset.GetTexture(), 255);

    const sgc::tile::TileSize2D size_xy = tileset.GetSizeInTiles();
    const sgc::tile::TileSize2D tileSize = tileset.GetTileSize();

    auto size_x = context.view.camera.w / size_xy.x;
    auto size_y = context.view.camera.h / size_xy.y;

    for (auto y = 0; y < size_y; ++y) {
        for (auto x = 0; x < size_x; ++x) {
            
            sgc::tile::TilePosition2D gridPos{ static_cast<sgc::math::uval>(x), static_cast<sgc::math::uval>(y) };

            auto tileIdOpt = tileStorage.GetTileAt(gridPos);

            if (!tileIdOpt.has_value()) {
                continue;
            }
            
            SDL_FRect srcRect = tileset.GetTileRect(tileIdOpt.value());
            SDL_FRect dstRect = {
                static_cast<float>(context.view.camera.x + x * tileSize.x),
                static_cast<float>(context.view.camera.y + y * tileSize.y),
                static_cast<float>(tileSize.x),
                static_cast<float>(tileSize.y)
            };

            SDL_RenderTexture(context.renderer, tileset.GetTexture(), &srcRect, &dstRect);
        }
    }
}
