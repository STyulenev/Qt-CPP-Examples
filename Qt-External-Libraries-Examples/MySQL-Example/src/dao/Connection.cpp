#include "Connection.h"

Connection::Connection(const QString hostName, const int port, const QString dataBaseName, const QString userName, const QString password) :
    hostName(hostName),
    port(port),
    dataBaseName(dataBaseName),
    userName(userName),
    password(password)
{
    msConnection = std::make_shared<MYSQL>(*mysql_init(nullptr));

    if (msConnection.get() == nullptr) {
        qDebug() << "Error: can't create MySQL-descriptor";
    }

    if (!mysql_real_connect(msConnection.get(),
                            hostName.toStdString().c_str(),
                            userName.toStdString().c_str(),
                            password.toStdString().c_str(),
                            dataBaseName.toStdString().c_str(),
                            port, nullptr, 0)) {
        qDebug() << "Error: can't connect to database " << QString(mysql_error(msConnection.get()));
    } else {
        qDebug() << "Success!";
    }
}

Connection::~Connection()
{
    mysql_close(msConnection.get());
}

auto Connection::getConnection() const -> std::shared_ptr<MYSQL>
{
    return msConnection;
}

auto Connection::query(const QString&& query) -> bool
{
    return mysql_query(msConnection.get(), query.toStdString().c_str());
}

auto Connection::query(const QString& query) -> bool
{
    return mysql_query(msConnection.get(), query.toStdString().c_str());
}

auto Connection::getLastError() const -> const QString
{
    return mysql_error(msConnection.get());
}
