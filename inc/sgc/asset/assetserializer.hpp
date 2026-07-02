#pragma once

#include <memory>
#include <vector>
#include <cstdint>

namespace sgc::asset
{
    template<typename T>
    class AssetSerializer
    {
        public:
            static std::vector<uint8_t> Serialize(std::shared_ptr<T> asset);
    };

}