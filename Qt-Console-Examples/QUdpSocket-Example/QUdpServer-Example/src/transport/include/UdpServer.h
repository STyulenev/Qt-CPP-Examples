#pragma once

#include "AbstractServer.h"

#include <QUdpSocket>

namespace Transport {

class UdpServer final : public AbstractServer
{
    Q_OBJECT

public:
    explicit UdpServer(QObject* parent = 0);
    virtual ~UdpServer();

    virtual void launch() override;

public slots:
    virtual void onReadyRead() override;

private:
    QUdpSocket* server;

};

} // namespace Transport
