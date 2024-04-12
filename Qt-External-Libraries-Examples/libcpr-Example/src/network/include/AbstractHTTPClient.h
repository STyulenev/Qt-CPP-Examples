#pragma once

#include <QObject>

namespace Network {

class AbstractHTTPClient : public QObject
{
    Q_OBJECT
public:
    AbstractHTTPClient(QObject* parent = 0) : QObject(parent) {}
    ~AbstractHTTPClient() = default;

    virtual auto getServerCurrentTime() -> void = 0;
    virtual auto getServerUserList() -> QString = 0;
    virtual auto postServerSendNewUser() -> QString = 0;
    virtual auto deleteServerFirstUser() -> QString = 0;

signals:
    auto serverCurrentTime(QString answer) -> void;

};

} // namespace Network
