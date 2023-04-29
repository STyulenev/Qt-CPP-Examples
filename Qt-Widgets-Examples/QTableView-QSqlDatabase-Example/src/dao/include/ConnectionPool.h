#pragma once

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

class ConnectionPool
{
private:
    static ConnectionPool* self;

    ConnectionPool();
    ConnectionPool(const ConnectionPool&);
    ConnectionPool& operator=(ConnectionPool&);

public:
    static auto getPool() -> ConnectionPool*;

    auto getConnection() -> std::shared_ptr<QSqlDatabase>;

    auto freeConnection(std::shared_ptr<QSqlDatabase> connection) -> void;

};
