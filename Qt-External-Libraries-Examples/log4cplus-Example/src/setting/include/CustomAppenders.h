#pragma once

#include <log4cplus/appender.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/layout.h>
#include <log4cplus/spi/loggingevent.h>
#include <log4cplus/helpers/property.h>

#include <sqlite3.h>

namespace Settings {

class SQLiteAppender : public log4cplus::Appender
{
public:
    SQLiteAppender(const std::string dbPath);

    SQLiteAppender(const log4cplus::helpers::Properties& properties);

    virtual ~SQLiteAppender();
    virtual void close() override;
    virtual void append(const log4cplus::spi::InternalLoggingEvent& event) override;

private:
    void createTable();
    void insertLog(log4cplus::LogLevel level, const log4cplus::tstring& logger, const log4cplus::tstring& message);

    sqlite3* db = nullptr;
};

typedef std::shared_ptr<SQLiteAppender> SharedSQLiteAppender;

} // namespace Settings
