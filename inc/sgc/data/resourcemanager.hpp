#pragma once

#include "sgc/data/package.hpp"
#include "sgc/data/asset.hpp"
#include "sgc/graphics/image.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/data/resourcecontext.hpp"
#include "sgc/asset/assetdeserializer.hpp"
#include <unordered_map>
#include <memory>

namespace sgc::data {

    class ResourceManager {

        private:
            Package* m_package = nullptr;
            // std::unordered_map<AssetId, std::shared_ptr<sgc::graphics::Image>> m_images;
            std::unordered_map<AssetId, std::shared_ptr<void>> m_cache;

        public:        
            void Mount(Package* package);
            // std::shared_ptr<sgc::graphics::Image> LoadImage(ResourceContext& context, AssetId id);    
            template<typename T>
            std::shared_ptr<T> LoadResource(AssetId id, ResourceContext& context);
    };

    template<typename T>
    std::shared_ptr<T> ResourceManager::LoadResource(
        AssetId id,
        ResourceContext& context
    )
    {
        // Check cache
        auto it = m_cache.find(id);
        if (it != m_cache.end())
        {
            return std::static_pointer_cast<T>(it->second);
        }

        // Read raw bytes from package
        const auto data = m_package->ReadAssetData(id);

        // Let the loader create the object
        std::shared_ptr<T> resource = sgc::asset::AssetDeserializer<T>::Deserialize(data);

        // Store in cache
        m_cache[id] = resource;

        return resource;
    }

}