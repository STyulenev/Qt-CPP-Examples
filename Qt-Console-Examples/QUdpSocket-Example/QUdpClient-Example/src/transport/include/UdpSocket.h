#pragma once

#include "AbstractSocket.h"

#include <QUdpSocket>

namespace Transport {

class UdpSocket final : public AbstractSocket
{
    Q_OBJECT

public:
    explicit UdpSocket(QObject* parent = 0);
    virtual ~UdpSocket();

    virtual void launch() override;
    virtual void onReadyWrite(const QByteArray& message)override;

public slots:
    virtual void onReadyRead() override;

private:
    QUdpSocket* socket;

};

} // namespace Transport
