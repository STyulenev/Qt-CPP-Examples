#include "ConnectionPool.h"

#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QDebug>

QMutex mutex;
QWaitCondition condition;
QQueue<std::shared_ptr<pqxx::connection>> connectionPool;

const int poolSize = 10;

ConnectionPool* ConnectionPool::self = 0;

ConnectionPool::ConnectionPool()
{
    for (int i = 0; i < poolSize; ++i) {
        std::shared_ptr<pqxx::connection> connection = std::make_shared<pqxx::connection> (
            "host='localhost' "
            "port='5432' "
            "dbname='test_db' "
            "user='postgres' "
            "password='tyulenev' "
        );
        connectionPool.enqueue(connection);
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

auto ConnectionPool::getConnection() -> std::shared_ptr<pqxx::connection>
{
    QMutexLocker locker(&mutex);
    qDebug() << "queue" << connectionPool.length();
    while (connectionPool.empty()) {
        condition.wait(&mutex);
    }

    return connectionPool.dequeue();
}

auto ConnectionPool::freeConnection(std::shared_ptr<pqxx::connection> connection) -> void
{
    qDebug() << "queue" << connectionPool.length();

    QMutexLocker locker(&mutex);
    connectionPool.enqueue(connection);
    condition.notify_one();

    qDebug() << "queue" << connectionPool.length();
}
