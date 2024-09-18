#include "Log.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>
#include <spdlog/common.h>
#include <vector>

std::shared_ptr<spdlog::logger> Log::m_logger;

void Log::init()
{
    static std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_st>("./logs/log.txt"));

    m_logger = std::make_shared<spdlog::logger>("log", begin(sinks), end(sinks));

    /*
    LOG_INFO("Initializing logger");
    LOG_WARN("Initializing logger");
    LOG_CRIT("Initializing logger");
    LOG_ERROR("Initializing logger");
    */
}
