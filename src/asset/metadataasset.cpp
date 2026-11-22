#include "sgc/asset/metadataasset.hpp"
#include "sgc/data/serialization.hpp"

using sgc::asset::AssetMetadata, sgc::asset::AssetSerializer, sgc::asset::AssetDeserializer;

AssetMetadata AssetDeserializer<AssetMetadata>::Deserialize(const std::vector<uint8_t>& bytes)
{
    sgc::data::BinaryReader reader{
        bytes.data(),
        0
    };

    AssetMetadata asset;

    asset.assetId = reader.Read<sgc::data::AssetId>();
    auto count = reader.Read<size_t>();

    for(auto i = 0; i < count; i++)
    {
        auto type = reader.Read<sgc::asset::MetadataType>();
        switch(type)
        {
            case MetadataType::Name:
            {
                auto name = reader.ReadString();

                if(!name.empty())
                {
                    asset.data[type] = name;
                }
                break;
            }
        }
    }

    return asset;
}

std::vector<uint8_t> AssetSerializer<AssetMetadata>::Serialize(const AssetMetadata &asset)
{
    sgc::data::BinaryWriter writer{};

    writer.Write(asset.assetId);
    writer.Write(asset.data.size());

    for(auto &[type, contents] : asset.data)
    {
        switch(type)
        {
            case MetadataType::Name:
            {
                if(std::holds_alternative<std::wstring>(contents))
                {
                    writer.Write(type);
                    writer.WriteString(std::get<std::wstring>(contents));
                }
                break;
            }
        }
    }

    return std::move(writer.buffer);
}