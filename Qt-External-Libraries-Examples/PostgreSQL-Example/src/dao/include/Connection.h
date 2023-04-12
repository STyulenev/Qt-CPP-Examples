#pragma once

#include "libpq-fe.h"
#include <QDebug>

class Connection
{
private:
    std::shared_ptr<PGconn> pgConnection;
    std::shared_ptr<PGresult> pgResult;

    QString hostName;
    QString port;
    QString dataBaseName;
    QString userName;
    QString password;
    QString lastError;

public:
    Connection(const QString hostName = "localhost", const QString port = "5432", const QString dataBaseName = "test_db",
               const QString userName = "postgres", const QString password = "tyulenev");
    ~Connection();

    auto getLastError() const -> const QString;

    auto getPostgreSQLVersion() -> int;

    auto isOpen() -> bool;

    auto getConnection() const -> const std::shared_ptr<PGconn>;

    auto runRequest(const QString&& request) -> PGresult*;

};
