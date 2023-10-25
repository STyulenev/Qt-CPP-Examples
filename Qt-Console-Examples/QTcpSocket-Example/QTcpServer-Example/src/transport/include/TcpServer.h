#pragma once

#include "AbstractServer.h"

#include <QTcpServer>
#include <QTcpSocket>

namespace Transport {

class TcpServer final : public AbstractServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject* parent = 0);
    virtual ~TcpServer();

    virtual void launch() override;

public slots:
    virtual void onNewConnection() override;
    virtual void onReadyRead() override;

private slots:
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    QTcpServer*         server;
    QList<QTcpSocket*>  socketsList;

};

} // namespace Transport
