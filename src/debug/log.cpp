#include "sgc/debug/log.hpp"
#include <print>

sgc::debug::LogMessage::LogMessage(std::string msg) : 
    level(LogLevel::Info), 
    message(std::move(msg)) 
{}

void sgc::debug::log(LogMessage msg) {    

    std::println("{}", msg.message);

}