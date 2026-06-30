#pragma once

#include <vector>
#include <string>

namespace sgc::data {

    struct BinaryWriter {
        std::vector<uint8_t> buffer;

        template<typename T>
        void Write(const T& value)
        {
            size_t oldSize = buffer.size();
            buffer.resize(oldSize + sizeof(T));

            std::memcpy(
                buffer.data() + oldSize,
                &value,
                sizeof(T));
        }
    };

    struct BinaryReader
    {
        const uint8_t* data;
        size_t offset = 0;

        template<typename T>
        T Read()
        {
            T value;
            std::memcpy(&value, data + offset, sizeof(T));
            offset += sizeof(T);
            return value;
        }
    };

}