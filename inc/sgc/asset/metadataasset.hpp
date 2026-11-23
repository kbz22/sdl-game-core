#pragma once

#include "sgc/data/asset.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include "sgc/asset/assetserializer.hpp"
#include <unordered_map>
#include <variant>

namespace sgc::asset
{
    using data::AssetId;
    using Metadata = std::variant<std::wstring>;

    enum class MetadataType : uint16_t
    {
        Name,
    };
    
    struct AssetMetadata
    {
        AssetId assetId;
        std::unordered_map<MetadataType, Metadata> data;
    };

    template<>
    struct AssetDeserializer<AssetMetadata>
    {
        static AssetMetadata Deserialize(const std::vector<uint8_t>& bytes);
    };

    template<>
    struct AssetSerializer<AssetMetadata>
    {
        public:
            static std::vector<uint8_t> Serialize(const AssetMetadata &asset);
    };
}