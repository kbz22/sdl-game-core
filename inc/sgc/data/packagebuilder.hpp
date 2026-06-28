#pragma once

#include "sgc/data/asset.hpp"
#include <vector>
#include <filesystem>

namespace sgc::data {

    class PackageBuilder
    {
    public:
        void AddAsset(
            AssetId id,
            AssetType type,
            const std::vector<uint8_t>& data);

        bool Save(const std::filesystem::path& path);

    private:
        struct PendingAsset
        {
            AssetId id;
            AssetType type;
            std::vector<uint8_t> data;
        };

        std::vector<PendingAsset> m_assets;
    };

}