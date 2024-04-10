#pragma once

#include "UserList.h"

class QHttpServer;

namespace Transport {

class HttpServer final : public QObject
{
    Q_OBJECT

public:
    explicit HttpServer(QObject* parent = 0);
    virtual ~HttpServer();

private:
    QHttpServer* httpServer;
    Models::UserList users;

};

} // namespace Transport
