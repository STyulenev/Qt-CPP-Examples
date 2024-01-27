#pragma once

#include <QObject>
#include <pqxx/pqxx>

class ConnectionPool
{
private:
    static ConnectionPool* self;

    ConnectionPool();
    ConnectionPool(const ConnectionPool&);
    ConnectionPool& operator=(ConnectionPool&);

public:
    static auto getPool() -> ConnectionPool*;

    auto getConnection() -> std::shared_ptr<pqxx::connection>;
    auto freeConnection(std::shared_ptr<pqxx::connection> connection) -> void;

};
