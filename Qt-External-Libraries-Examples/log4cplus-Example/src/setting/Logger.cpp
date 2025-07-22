#include "Logger.h"

namespace Settings {

Logger* Logger::self = 0;

namespace
{
    SharedFileAppenderPtr fileAppender;
    SharedConsoleAppenderPtr consoleAppender;
}

Logger::Logger()
{

}

Logger::~Logger()
{

}

Logger* Logger::instance()
{
    if (!self) {
        self = new Logger();
    }

    return self;
}

bool Logger::initialization()
{
    try {


        // Очищаем старые аппендеры
        log4cplus::Logger::getRoot().removeAllAppenders();  // Удаляем все предыдущие аппендеры

#ifndef QT_DEBUG
        // Консольный аппендер
        consoleAppender = new log4cplus::ConsoleAppender();
        log4cplus::tstring consolePattern = L"%d{%Y-%m-%d %H:%M:%S,%q} [%p] %m [%l]%n";
        consoleAppender->setName(L"console-appender");
        consoleAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(consolePattern)));

        // Добавляем новые аппендеры корневому логгеру

        log4cplus::Logger::getRoot().addAppender(log4cplus::SharedAppenderPtr(consoleAppender.get()));
#else
        // Файловый аппендер
        log4cplus::helpers::Properties fileProps;
        fileProps.setProperty(L"AsyncAppend", L"true");
        fileProps.setProperty(L"File", L"C:\\Work\\log.txt");
        fileProps.setProperty(L"Schedule", L"DAILY");
        fileProps.setProperty(L"ImmediateFlush", L"true");
        fileProps.setProperty(L"DatePattern", L"%Y-%m-%d");
        fileProps.setProperty(L"MaxBackupIndex", L"0");
        fileProps.setProperty(L"CreateDirs", L"true");
        fileProps.setProperty(L"RollOnClose", L"false");

        fileAppender = new log4cplus::DailyRollingFileAppender(fileProps);
        log4cplus::tstring filePattern = L"%d{%Y-%m-%d %H:%M:%S,%q} [%p] %m [%l]%n";
        fileAppender->setName(L"file-appender");
        fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(filePattern)));

        // Добавляем новый аппендер корневому логгеру
        log4cplus::Logger::getRoot().addAppender(log4cplus::SharedAppenderPtr(fileAppender.get()));
#endif

        LOG4CPLUS_INFO(_logger, LOG4CPLUS_TEXT("Logger is init"));
    } catch (...) {
        return false;
    }

    return true;
}

} // namespace Settings
