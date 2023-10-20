#pragma once

#include <QObject>

namespace Transport {

class AbstractSocket : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSocket(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~AbstractSocket() = default;

    virtual void launch() = 0;
    virtual void onReadyWrite(const QByteArray& message) = 0;

protected slots:
    virtual void onReadyRead() = 0;

signals:
    void getMessage(const QString& message);
    void error(const QString& error);
    void write(const QByteArray& message);

};

} // namespace Transport
