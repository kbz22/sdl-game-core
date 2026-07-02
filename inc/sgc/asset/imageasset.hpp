#pragma once

#include <vector>

namespace sgc::asset {

    // This is basically a wrapper for a PNG
    struct ImageAsset
    {
        std::vector<uint8_t> data;
    };

}