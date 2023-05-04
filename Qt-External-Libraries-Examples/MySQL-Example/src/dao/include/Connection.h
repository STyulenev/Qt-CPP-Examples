#pragma once

#include "mysql.h"
#include <QDebug>

class Connection
{
private:
    std::shared_ptr<MYSQL> msConnection;

    QString hostName;
    int     port;
    QString dataBaseName;
    QString userName;
    QString password;

    QString lastError;

public:
    //Connection() = delete;
    Connection(const QString hostName = "localhost", const int port = 3306, const QString dataBaseName = "test_db",
               const QString userName = "postgres", const QString password = "tyulenev");
    ~Connection();

    auto getConnection() const -> std::shared_ptr<MYSQL>;

    auto query(const QString&& query) -> bool;

    auto query(const QString& query) -> bool;

    auto getLastError() const -> const QString;

};


/*

auto getPostgreSQLVersion() -> int;

auto runRequest(const QString&& request) -> PGresult*;
*/
