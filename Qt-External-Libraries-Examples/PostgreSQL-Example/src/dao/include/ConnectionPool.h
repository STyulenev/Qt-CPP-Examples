#pragma once

#include "Connection.h"

class ConnectionPool
{
private:
    static ConnectionPool* self;

    ConnectionPool();
    ConnectionPool(const ConnectionPool&);
    ConnectionPool& operator=(ConnectionPool&);

public:
    static auto getPool() -> ConnectionPool*;

    auto getConnection() -> std::shared_ptr<Connection>;
    auto freeConnection(std::shared_ptr<Connection> connection) -> void;

};
