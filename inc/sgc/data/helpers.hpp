#pragma once

#include <vector>
#include <filesystem>

namespace sgc::data {

    std::vector<uint8_t> ReadFile(const std::filesystem::path& path);

}