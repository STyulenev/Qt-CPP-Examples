#include "Logger.h"

#include "CustomAppenders.h"

namespace Settings {

Logger* Logger::self = 0;

namespace
{
    SharedSQLiteAppender     sqlAppender;
    SharedFileAppenderPtr    fileAppender;
    SharedConsoleAppenderPtr consoleAppender;
}

Logger::Logger()
{
    // ...
}

Logger::~Logger()
{
    // ...
}

Logger* Logger::instance()
{
    if (!self)
    {
        self = new Logger();
    }

    return self;
}

bool Logger::initialization()
{
    try
    {
        // Очищаем старые аппендеры
        log4cplus::Logger::getRoot().removeAllAppenders();  // Удаляем все предыдущие аппендеры

        // БД аппендер
        log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));

        sqlAppender = std::make_shared<SQLiteAppender>("application.db");
        log4cplus::tstring sqlPattern = L"%d{%Y-%m-%d %H:%M:%S,%q} [%p] %m [%l]%n";
        sqlAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(sqlPattern)));

        // Добавляем новый аппендеры корневому логгеру
        log4cplus::Logger::getRoot().addAppender(log4cplus::SharedAppenderPtr(sqlAppender.get()));



        // // Консольный аппендер
        // consoleAppender = new log4cplus::ConsoleAppender();
        // log4cplus::tstring consolePattern = L"%d{%Y-%m-%d %H:%M:%S,%q} [%p] %m [%l]%n";
        // consoleAppender->setName(L"console-appender");
        // consoleAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(consolePattern)));

        // // Добавляем новый аппендеры корневому логгеру
        // log4cplus::Logger::getRoot().addAppender(log4cplus::SharedAppenderPtr(consoleAppender.get()));



        // // Файловый аппендер
        // log4cplus::helpers::Properties fileProps;
        // fileProps.setProperty(L"AsyncAppend", L"true");
        // fileProps.setProperty(L"File", L"C:\\Work\\log.txt");
        // fileProps.setProperty(L"Schedule", L"DAILY");
        // fileProps.setProperty(L"ImmediateFlush", L"true");
        // fileProps.setProperty(L"DatePattern", L"%Y-%m-%d");
        // fileProps.setProperty(L"MaxBackupIndex", L"0");
        // fileProps.setProperty(L"CreateDirs", L"true");
        // fileProps.setProperty(L"RollOnClose", L"false");

        // fileAppender = new log4cplus::DailyRollingFileAppender(fileProps);
        // log4cplus::tstring filePattern = L"%d{%Y-%m-%d %H:%M:%S,%q} [%p] %m [%l]%n";
        // fileAppender->setName(L"file-appender");
        // fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(filePattern)));

        // // Добавляем новый аппендер корневому логгеру
        // log4cplus::Logger::getRoot().addAppender(log4cplus::SharedAppenderPtr(fileAppender.get()));

        LOG4CPLUS_INFO(_logger, LOG4CPLUS_TEXT("Logger is init"));
    }
    catch (...)
    {
        return false;
    }

    return true;
}

} // namespace Settings
