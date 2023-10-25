#pragma once

#include <QObject>

namespace Transport {

class AbstractSocket : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSocket(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~AbstractSocket() = default;

    virtual auto launch() -> void = 0;
    virtual auto onReadyWrite(const QByteArray& message) -> void = 0;

public slots:
    virtual void onReadyRead() = 0;

signals:
    void getMessage(const QString& message);
    void error(const QString& error);
    void write(const QByteArray& message);

};

} // namespace Transport
