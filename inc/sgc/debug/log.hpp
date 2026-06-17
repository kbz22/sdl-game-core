#pragma once

#include <string>

namespace sgc::debug {

    enum class LogLevel {
        Info,
        Warning,
        Error
    };

    struct LogMessage {
        LogLevel level = LogLevel::Info;
        std::string message{};

        LogMessage(std::string msg);
    };

    void log(LogMessage msg);

}