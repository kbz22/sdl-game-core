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

        void WriteString(const std::wstring& str)
        {
            size_t strLength = str.size();
            Write(strLength);
            
            size_t oldSize = buffer.size();
            size_t strSize = strLength * sizeof(wchar_t);
            buffer.resize(oldSize + strSize);

            std::memcpy(
                buffer.data() + oldSize,
                str.data(),
                strSize);
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

        std::wstring ReadString()
        {
            size_t length = Read<size_t>();
            std::wstring str(length, L'\0');
            std::memcpy(str.data(), data + offset, length * sizeof(wchar_t));
            offset += length * sizeof(wchar_t);
            return str;
        }
    };

}