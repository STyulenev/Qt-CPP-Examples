#pragma once

#include <QObject>

namespace Transport {

class AbstractServer : public QObject
{
    Q_OBJECT
public:
    explicit AbstractServer(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~AbstractServer() = default;

    virtual void launch() = 0;

protected slots:
    virtual void onReadyRead() = 0;

signals:
    void getMessage(const QString& message);
    void error(const QString& error);

};

} // namespace Transport
