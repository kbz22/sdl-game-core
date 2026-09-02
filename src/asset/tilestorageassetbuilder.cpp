#include "sgc/asset/tilestorageasset.hpp"
#include "sgc/asset/chunkedtilestorageasset.hpp"
#include "sgc/data/chunkedtilestorage.hpp"
#include <stdexcept>

sgc::asset::TileStorageAsset sgc::asset::AssetBuilder<sgc::asset::TileStorageAsset, sgc::data::ITileStorage>::Build(const sgc::data::ITileStorage &asset)
{
    if(auto chunkedStorage = dynamic_cast<const sgc::data::ChunkedTileStorage*>(&asset)) {
        return AssetBuilder<sgc::asset::ChunkedTileStorageAsset, sgc::data::ChunkedTileStorage>::Build(*chunkedStorage);
    }

    throw std::runtime_error("Unsupported ITileStorage type for building TileStorageAsset.");
}