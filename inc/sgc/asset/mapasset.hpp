#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/data/layertagid.hpp"
#include "sgc/text/text.hpp"
#include <vector>

namespace sgc::asset {

    struct MapLayerAsset
    {
        sgc::text::String name;
        sgc::data::AssetId storageId;
        std::vector<sgc::data::LayerTagId> tags;
    };

    struct MapAsset
    {
        sgc::data::AssetId tilesetId;
        std::vector<MapLayerAsset> layers;
    };

}