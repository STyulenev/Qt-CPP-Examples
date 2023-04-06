#pragma once

#include <libpq-fe.h>
#include <QDebug>

class Connection
{
public:
    Connection(const QString hostName = "localhost", const QString port = "5432", const QString dataBaseName = "test_pharmacy",
               const QString userName = "postgres", const QString password = "tyulenev");
    ~Connection();

    auto getLastError() const -> const QString;
    auto getPostgreSQLVersion() -> int;
    auto isOpen() -> bool;

private:
    std::shared_ptr<PGconn>  pgConnection;

    QString hostName;
    QString port;
    QString dataBaseName;
    QString userName;
    QString password;
    QString lastError;

};
