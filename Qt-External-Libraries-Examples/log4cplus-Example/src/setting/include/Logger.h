#pragma once

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>

typedef log4cplus::helpers::SharedObjectPtr<log4cplus::FileAppender> SharedFileAppenderPtr;
typedef log4cplus::helpers::SharedObjectPtr<log4cplus::ConsoleAppender> SharedConsoleAppenderPtr;

#ifndef LOG_WARN
#define LOG_WARN(text)\
    do {\
        LOG4CPLUS_WARN(Settings::_logger, LOG4CPLUS_TEXT(text));\
    } while(false)
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(text)\
    do {\
            LOG4CPLUS_ERROR(Settings::_logger, LOG4CPLUS_TEXT(text));\
    } while(false)
#endif

#ifndef LOG_INFO
#define LOG_INFO(text)\
do {\
        LOG4CPLUS_INFO(Settings::_logger, LOG4CPLUS_TEXT(text));\
} while(false)
#endif

namespace Settings {

inline log4cplus::Logger _logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));

class Logger final
{
private:
    static Logger* self;

    Logger();
    ~Logger();

public:
    Logger(const Logger&) = delete;
    Logger& operator=(Logger&) = delete;
    Logger(const Logger&&) = delete;
    Logger&& operator=(Logger&&) = delete;

    static Logger* instance();

    bool initialization();
};

} // namespace Settings
