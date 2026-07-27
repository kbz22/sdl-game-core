#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/data/layertagid.hpp"
#include "sgc/asset/tilestorageasset.hpp"
#include "sgc/text/text.hpp"
#include <vector>
#include <memory>

namespace sgc::asset {
    
    struct MapLayerAsset
    {
        sgc::text::String name;
        std::vector<sgc::data::LayerTagId> tags;
        TileStorageAsset tileStorage;
    };

    struct MapAsset
    {
        sgc::data::AssetId tilesetId;
        std::vector<MapLayerAsset> layers;
    };

}