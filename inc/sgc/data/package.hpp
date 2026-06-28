#pragma once

#include "sgc/data/asset.hpp"
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <filesystem>
#include <vector>

namespace sgc::data {

    struct PackageHeader {
        char magic[4];
        uint32_t version;
        uint32_t assetCount;
        uint32_t assetTableOffset;
    };

    struct PackageEntry {
        AssetId id;
        AssetType type;
        uint32_t offset;
        uint32_t size;
    };

    class Package {

        private:
            std::ifstream m_stream;
            std::unordered_map<AssetId, PackageEntry> m_entries;

        public:
            Package() = default;

            bool Open(const std::filesystem::path& path);
            bool HasAsset(AssetId id) const;
            const PackageEntry& GetAssetEntry(AssetId id) const;

            std::vector<uint8_t> ReadAssetData(AssetId id) const;


    };

}