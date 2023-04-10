#pragma once

#include <libpq-fe.h>
#include <QDebug>

class Connection
{
public:
    Connection(const QString hostName = "localhost", const QString port = "5432", const QString dataBaseName = "test_db",
               const QString userName = "postgres", const QString password = "tyulenev");
    ~Connection();

    auto getLastError() const -> const QString;
    auto getPostgreSQLVersion() -> int;
    auto isOpen() -> bool;

    const std::shared_ptr<PGconn> &getConnection() const;

    auto runRequest(const QString&&) -> PGresult*;

private:
    std::shared_ptr<PGconn> pgConnection;
    std::shared_ptr<PGresult> pgResult;

    QString hostName;
    QString port;
    QString dataBaseName;
    QString userName;
    QString password;
    QString lastError;

};
