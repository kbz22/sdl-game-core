#pragma once

#include <memory>
#include <vector>

namespace sgc::asset {

    template<typename AssetT>
    struct AssetDeserializer
    {
        static AssetT Deserialize(
            const std::vector<uint8_t>& data
        );
    };

}