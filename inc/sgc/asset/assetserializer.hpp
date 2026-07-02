#pragma once

#include <memory>
#include <vector>
#include <cstdint>

namespace sgc::asset
{
    template<typename T>
    struct AssetSerializer
    {
        public:
            static std::vector<uint8_t> Serialize(const T &asset);
    };

}