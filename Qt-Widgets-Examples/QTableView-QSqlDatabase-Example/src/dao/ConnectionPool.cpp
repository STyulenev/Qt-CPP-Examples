#include "ConnectionPool.h"

#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

QMutex mutex;
QWaitCondition condition;
QQueue<std::shared_ptr<QSqlDatabase>> connectionPool;

const int poolSize = 10;

ConnectionPool* ConnectionPool::self = 0;

ConnectionPool::ConnectionPool()
{
    for (int i = 0; i < poolSize; ++i) {
        std::shared_ptr<QSqlDatabase> connection = std::make_shared<QSqlDatabase>(QSqlDatabase::addDatabase("QPSQL", QString("Connection_%1").arg(i)));

        connection->setDatabaseName("test_db");
        connection->setPort(5432);
        connection->setUserName("postgres");
        connection->setHostName("localhost");
        connection->setPassword("tyulenev");

        connectionPool.enqueue(std::move(connection));
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

auto ConnectionPool::getConnection() -> std::shared_ptr<QSqlDatabase>
{
    QMutexLocker locker(&mutex);

    while (connectionPool.empty()) {
        condition.wait(&mutex);
    }

    return connectionPool.dequeue();
}

auto ConnectionPool::freeConnection(std::shared_ptr<QSqlDatabase> connection) -> void
{
    QMutexLocker locker(&mutex);
    connectionPool.enqueue(connection);
    condition.notify_one();
}
