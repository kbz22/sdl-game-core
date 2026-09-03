#pragma once

#include "sgc/data/asset.hpp"
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace sgc::data {

    class PackageBuilder
    {
        private:
            // std::vector<BinaryAsset> m_assets;
            std::unordered_map<AssetId, BinaryAsset> m_assetMap;

        public:
            void AddAsset(
                AssetId id,
                AssetType type,
                const std::vector<uint8_t>& data
            );

            void AddAsset(
                BinaryAsset asset
            );

            bool Save(const std::filesystem::path& path);
            std::vector<uint8_t> Build();
    };

}