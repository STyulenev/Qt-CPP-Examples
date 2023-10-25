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

    virtual auto launch() -> void override;
    virtual auto onReadyWrite(const QByteArray& message) -> void override;

public slots:
    virtual void onReadyRead() override;

private:
    QTcpSocket* socket;

};

} // namespace Transport
