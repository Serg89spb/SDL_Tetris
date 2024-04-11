#pragma once

#include "spdlog/spdlog.h"

namespace Tetris
{

class Log
{
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

private:
    static std::shared_ptr<spdlog::logger> s_Logger;
};

}  // namespace Tetris

#define TETRIS_TRACE(...) ::Tetris::Log::GetLogger()->trace(__VA_ARGS__)
#define TETRIS_INFO(...) ::Tetris::Log::GetLogger()->info(__VA_ARGS__)
#define TETRIS_WARN(...) ::Tetris::Log::GetLogger()->warn(__VA_ARGS__)
#define TETRIS_ERROR(...) ::Tetris::Log::GetLogger()->error(__VA_ARGS__)
