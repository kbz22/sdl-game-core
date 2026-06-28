#include "sgc/data/helpers.hpp"
#include <fstream>

std::vector<uint8_t> sgc::data::ReadFile(const std::filesystem::path& path)
{
    std::ifstream file(path, std::ios::binary);

    if (!file.is_open())
        return {};
   
    file.seekg(0, std::ios::end);
    size_t size = static_cast<size_t>(file.tellg());

     if (size == 0 /* || size > MAX_REASONABLE_FILE_SIZE */) //! tbd
        return {};

    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> data(size);

    file.read(
        reinterpret_cast<char*>(data.data()),
        size);

    return data;
}