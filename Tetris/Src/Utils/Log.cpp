#include <memory>

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace tetris
{
std::shared_ptr<spdlog::logger> Log::s_logger_;

void Log::init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_logger_ = spdlog::stdout_color_mt("TETRIS");
    s_logger_->set_level(spdlog::level::trace);
}
}  // namespace tetris