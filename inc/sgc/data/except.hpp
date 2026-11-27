#include <stdexcept>

namespace sgc::data
{
    class PackageAssetNotFound : public std::runtime_error
    {
        public:
            PackageAssetNotFound(const std::string &message) : std::runtime_error{message} {}
    };
}