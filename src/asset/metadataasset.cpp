#include "sgc/asset/metadataasset.hpp"
#include "sgc/data/serialization.hpp"
#include <stdexcept>

using sgc::asset::AssetMetadata, sgc::asset::AssetSerializer, sgc::asset::AssetDeserializer;

AssetMetadata AssetDeserializer<AssetMetadata>::Deserialize(const std::vector<uint8_t>& bytes)
{
    sgc::data::BinaryReader reader{
        bytes.data(),
        0
    };

    AssetMetadata asset;    
    auto assetCount = reader.Read<size_t>();

    for(auto i = 0; i < assetCount; i++)
    {
        auto assetId = reader.Read<sgc::data::AssetId>();
        auto dataCount = reader.Read<size_t>();

        for(auto k = 0; k < dataCount; k++)
        {
            auto type = reader.Read<sgc::asset::MetadataType>();
            switch(type)
            {
                case MetadataType::Name:
                {
                    auto name = reader.ReadString();

                    if(!name.empty())
                    {
                        asset.data[assetId][type] = name;
                    }
                    break;
                }
            }
        }        
    }

    return asset;
}

std::vector<uint8_t> AssetSerializer<AssetMetadata>::Serialize(const AssetMetadata &asset)
{
    sgc::data::BinaryWriter writer;

    writer.Write(asset.data.size());

    for(auto &[id, metamap] : asset.data)
    {
        writer.Write(id);
        writer.Write(metamap.size());

        for(auto &[type, data] : metamap)
        {
            switch(type)
            {
                case MetadataType::Name:
                {
                    auto entry = metamap.at(type);
                    if(std::holds_alternative<std::wstring>(entry))
                    {
                        writer.Write(type);
                        writer.WriteString(std::get<std::wstring>(entry));
                        break;
                    }
                    throw std::runtime_error("Failed to write metadata asset.");
                }
            }
        }
    }

    return std::move(writer.buffer);
}