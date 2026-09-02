#pragma once

#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/asset/assetbuilder.hpp"
#include "sgc/data/itilestorage.hpp"
#include <variant>

namespace sgc::asset {

    using TileStorageAsset = std::variant<
        ChunkedTileStorageAsset
    >;

    template<>
    struct AssetBuilder<TileStorageAsset, sgc::data::ITileStorage>
    {
        public:
            static TileStorageAsset Build(const sgc::data::ITileStorage &asset);
    };

}