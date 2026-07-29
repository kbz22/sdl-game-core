#include "sgc/asset/tilestorageassetbuilder.hpp"
#include "sgc/asset/chunkedtilestorageassetbuilder.hpp"
#include "sgc/data/chunkedtilestorage.hpp"
#include <stdexcept>

sgc::asset::TileStorageAsset sgc::asset::AssetBuilder<sgc::asset::TileStorageAsset>::Build(const sgc::data::ITileStorage &asset)
{
    if(auto chunkedStorage = dynamic_cast<const sgc::data::ChunkedTileStorage*>(&asset)) {
        return AssetBuilder<sgc::asset::ChunkedTileStorageAsset>::Build(*chunkedStorage);
    }

    throw std::runtime_error("Unsupported ITileStorage type for building TileStorageAsset.");
}