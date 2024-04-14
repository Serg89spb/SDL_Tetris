#pragma once

#include "spdlog/spdlog.h"

namespace tetris
{

class Log
{
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& get_logger() { return s_logger_; }

private:
    static std::shared_ptr<spdlog::logger> s_logger_;
};

}  // namespace tetris

#define TETRIS_TRACE(...) ::tetris::Log::get_logger()->trace(__VA_ARGS__)
#define TETRIS_INFO(...) ::tetris::Log::get_logger()->info(__VA_ARGS__)
#define TETRIS_WARN(...) ::tetris::Log::get_logger()->warn(__VA_ARGS__)
#define TETRIS_ERROR(...) ::tetris::Log::get_logger()->error(__VA_ARGS__)
