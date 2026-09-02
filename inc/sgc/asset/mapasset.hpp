#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/data/layertagid.hpp"
#include "sgc/asset/tilestorageasset.hpp"
#include "sgc/text/text.hpp"
#include "sgc/asset/assetbuilder.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/assetserializer.hpp"
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

    template<>
    struct AssetDeserializer<MapAsset>
    {
        static MapAsset Deserialize(const std::vector<uint8_t>& bytes);
    };

    template<>
    struct AssetSerializer<MapAsset>
    {
        public:
            static std::vector<uint8_t> Serialize(const MapAsset &asset);
    };

}