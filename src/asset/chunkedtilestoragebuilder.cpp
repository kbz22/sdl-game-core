#include "sgc/asset/chunkedtilestoragebuilder.hpp"

std::shared_ptr<sgc::data::ChunkedTileStorage> sgc::asset::RuntimeBuilder<sgc::data::ChunkedTileStorage>::Build(const ChunkedTileStorageAsset& asset)
{
    auto chunkedTileStorage = std::make_shared<sgc::data::ChunkedTileStorage>();

    for(const auto& chunkAsset : asset.chunks) {
        chunkedTileStorage->SetChunkAt(chunkAsset.position, chunkAsset.chunk);
    }

    return chunkedTileStorage;
}