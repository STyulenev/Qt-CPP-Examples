#include "Connection.h"

Connection::Connection(const QString hostName, const QString port, const QString dataBaseName, const QString userName, const QString password) :
    hostName(hostName),
    port(port),
    dataBaseName(dataBaseName),
    userName(userName),
    password(password)
{
    pgConnection.reset(PQsetdbLogin(hostName.toStdString().c_str(),
                                    port.toStdString().c_str(),
                                    nullptr,
                                    nullptr,
                                    dataBaseName.toStdString().c_str(),
                                    userName.toStdString().c_str(),
                                    password.toStdString().c_str()), &PQfinish );
}

Connection::~Connection()
{

}

auto Connection::getLastError() const -> const QString
{
    return PQerrorMessage(pgConnection.get());
}

auto Connection::getPostgreSQLVersion() -> int
{
    return PQlibVersion();
}

auto Connection::isOpen() -> bool
{
    return PQstatus(pgConnection.get()) == CONNECTION_OK;
}

const std::shared_ptr<PGconn>& Connection::getConnection() const
{
    return pgConnection;
}

auto Connection::runRequest(const QString&& request) -> PGresult*
{
   // pgResult =
    return PQexec(pgConnection.get(), request.toStdString().c_str());
            //std::make_shared<PGresult>(PQexec(pgConnection.get(), request.toStdString().c_str()));
            //PQexec(pgConnection.get(), request.toStdString().c_str());
}
