#pragma once

#include <soci/soci.h>
#include <soci/connection-pool.h>

class ConnectionPool
{
private:
    static ConnectionPool* self;

    ConnectionPool();
    ConnectionPool(const ConnectionPool&);
    ConnectionPool& operator=(ConnectionPool&);

public:
    static auto getPool() -> ConnectionPool*;

    auto getConnection() -> std::shared_ptr<soci::session>;
    auto freeConnection(std::shared_ptr<soci::session> connection) -> void;

};

