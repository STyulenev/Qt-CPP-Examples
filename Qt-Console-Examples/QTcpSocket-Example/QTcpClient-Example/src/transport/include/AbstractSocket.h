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
    virtual auto onReadyRead() -> void = 0;

signals:
    auto getMessage(const QString& message) -> void;
    auto error(const QString& error) -> void;
    auto write(const QByteArray& message) -> void;

};

} // namespace Transport
