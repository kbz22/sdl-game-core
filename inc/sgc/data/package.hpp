#pragma once

#include "sgc/data/asset.hpp"
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <filesystem>
#include <vector>
#include <span>

namespace sgc::data {

    constexpr size_t c_packageMagicSize = 4;
    constexpr inline uint8_t c_packageMagic[c_packageMagicSize] = { 'S', 'G', 'C', 'P' };

    struct PackageHeader {
        uint8_t magic[c_packageMagicSize];
        uint32_t version;
        uint32_t assetCount;
        size_t tableOffset;
        size_t dataOffset;
    };

    struct PackageEntry {
        AssetId id;
        AssetType type;
        size_t offset;
        size_t size;
    };

    class Package 
    {
        private:
            // mutable std::ifstream m_stream;
            std::vector<uint8_t> m_data;
            std::unordered_map<AssetId, PackageEntry> m_entries;
            size_t m_dataOffset = 0;
            size_t m_fileSize = 0;
                
        public:
            bool Open(const std::filesystem::path& path);
            bool Open(std::span<uint8_t> data);

            bool HasAsset(AssetId id) const;
            const PackageEntry& GetEntry(AssetId id) const;
            std::vector<uint8_t> ReadAssetData(AssetId id) const;

            auto begin() { return m_entries.begin(); }
            auto end()   { return m_entries.end(); }
            auto begin() const { return m_entries.begin(); }
            auto end()   const { return m_entries.end(); }
            auto cbegin() const { return m_entries.cbegin(); }
            auto cend()   const { return m_entries.cend(); }
    };
}
