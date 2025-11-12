#include "CustomAppenders.h"

#include <iostream>

namespace Settings {

SQLiteAppender::SQLiteAppender(const std::string dbPath)
{
    int rc = sqlite3_open(log4cplus::helpers::tostring(dbPath).c_str(), &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    createTable();
}

SQLiteAppender::SQLiteAppender(const log4cplus::helpers::Properties& properties)
{
    log4cplus::tstring dbPath = properties.getProperty(LOG4CPLUS_TEXT("dbfile"), LOG4CPLUS_TEXT("logs.db"));
    int rc = sqlite3_open(log4cplus::helpers::tostring(dbPath).c_str(), &db);

    if (rc == SQLITE_OK)
    {
        createTable();
    }
}

SQLiteAppender::~SQLiteAppender()
{
    close();
}

void SQLiteAppender::close()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

void SQLiteAppender::append(const log4cplus::spi::InternalLoggingEvent &event)
{
    if (!db)
    {
        return;
    }

    // Используем публичные методы для получения данных
    log4cplus::tstring loggerName = event.getLoggerName();
    log4cplus::tstring message = event.getMessage();
    log4cplus::LogLevel logLevel = event.getLogLevel();

    // Форматируем сообщение с помощью layout, если он установлен
    /*log4cplus::tstring formattedMessage;
    if (layout)
    {
        log4cplus::tostringstream buffer;
        layout->formatAndAppend(buffer, event);
        formattedMessage = buffer.str();
    } else
    {
        formattedMessage = message;
    }*/

    insertLog(logLevel, loggerName, message);
}

void SQLiteAppender::createTable()
{
    const char* sql = "CREATE TABLE IF NOT EXISTS logs ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                      "level TEXT NOT NULL, "
                      "file TEXT NOT NULL, "
                      "message TEXT);";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Создаем индекс для улучшения производительности запросов
    const char* indexSql = "CREATE INDEX IF NOT EXISTS idx_level ON logs(level);";
    sqlite3_exec(db, indexSql, nullptr, nullptr, nullptr);
}

void SQLiteAppender::insertLog(log4cplus::LogLevel level, const log4cplus::tstring &logger, const log4cplus::tstring &message)
{
    const char* sql = "INSERT INTO logs (level, file, message) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        return;
    }

    std::string levelStr   = log4cplus::helpers::tostring(log4cplus::getLogLevelManager().toString(level));
    std::string loggerStr  = log4cplus::helpers::tostring(logger);
    std::string messageStr = log4cplus::helpers::tostring(message);

    sqlite3_bind_text(stmt, 1, levelStr.c_str(),   -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, loggerStr.c_str(),  -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, messageStr.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}


} // namespace Settings
