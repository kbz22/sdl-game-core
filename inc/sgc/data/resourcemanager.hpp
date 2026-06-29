#pragma once

#include "sgc/data/package.hpp"
#include "sgc/data/asset.hpp"
#include "sgc/graphics/image.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include <unordered_map>

namespace sgc::data {

    struct ResourceContext {
        SDL_Renderer* renderer;
    };

    class ResourceManager {

        private:
            Package* m_package = nullptr;
            std::unordered_map<AssetId, sgc::graphics::Image> m_images;

        public:        
            void Mount(Package* package);
            sgc::graphics::Image& LoadImage(ResourceContext& context, AssetId id);

    
    };

}