#pragma once

#include "AbstractSocket.h"

#include <QTcpSocket>

namespace Transport {

class TcpSocket final : public AbstractSocket
{
    Q_OBJECT

public:
    explicit TcpSocket(QObject* parent = 0);
    virtual ~TcpSocket();

    virtual void launch() override;
    virtual void onReadyWrite(const QByteArray& message) override;

public slots:
    virtual void onReadyRead() override;

private:
    QTcpSocket* socket;

};

} // namespace Transport
