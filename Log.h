#pragma once

#include "spdlog/spdlog.h"

#include <memory>
#include <shared_mutex>
#include <spdlog/sinks/basic_file_sink.h>


class Log {
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger() {return m_logger;}
private:
    static std::shared_ptr<spdlog::logger> m_logger;
};

#ifdef DEBUG
#define LOG_INFO(...) Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRIT(...) Log::GetLogger()->critical(__VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_CRIT(...)
#endif
