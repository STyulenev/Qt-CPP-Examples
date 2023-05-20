#include "ConnectionPool.h"

#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QDebug>

QMutex mutex;
QWaitCondition condition;
QQueue<std::shared_ptr<Connection>> connectionPool;

const int poolSize = 10;

ConnectionPool* ConnectionPool::self = 0;

ConnectionPool::ConnectionPool()
{
    for (int i = 0; i < poolSize; ++i) {
        connectionPool.enqueue(std::make_shared<Connection>());
    }
}

auto ConnectionPool::getPool() -> ConnectionPool*
{
    QMutexLocker locker(&mutex);

    if (!self) {
        self = new ConnectionPool();
    }

    return self;
}

auto ConnectionPool::getConnection() -> std::shared_ptr<Connection>
{
    QMutexLocker locker(&mutex);

    while (connectionPool.empty()) {
        condition.wait(&mutex);
    }

    return connectionPool.dequeue();
}

auto ConnectionPool::freeConnection(std::shared_ptr<Connection> connection) -> void
{
    QMutexLocker locker(&mutex);
    connectionPool.enqueue(connection);
    condition.notify_one();
}
