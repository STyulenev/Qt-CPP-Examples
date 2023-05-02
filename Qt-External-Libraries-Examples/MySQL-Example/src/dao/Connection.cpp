#include "Connection.h"

Connection::Connection(const QString hostName, const int port, const QString dataBaseName, const QString userName, const QString password) :
    hostName(hostName),
    port(port),
    dataBaseName(dataBaseName),
    userName(userName),
    password(password)
{
    msConnection = std::make_shared<MYSQL>(*mysql_init(nullptr)); // ?

    if (msConnection.get() == nullptr) {
        // Если дескриптор не получен – выводим сообщение об ошибке
        qDebug() << "Error: can't create MySQL-descriptor";
    }
}

Connection::~Connection()
{
    //mysql_close(msConnection.get());
}

auto Connection::open() -> bool
{
    // Подключаемся к серверу
    if (!mysql_real_connect(msConnection.get(), "localhost", "root", "tyulenev", "test_db", 3306, nullptr, 0)) {
        qDebug() << "Error: can't connect to database " << QString(mysql_error(msConnection.get()));
        return false;
    } else {
        // Если соединение успешно установлено выводим фразу - "Success!"
        qDebug() << "Success!";
        return true;
    }
    //return this->status;
}

auto Connection::close() -> void
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

auto Connection::getLastError() const -> const QString
{
    return lastError; //mysql_error(msConnection.get());
}
