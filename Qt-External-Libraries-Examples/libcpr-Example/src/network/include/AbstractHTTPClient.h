#pragma once

#include <QObject>

namespace Network {

class AbstractHTTPClient : public QObject
{
    Q_OBJECT

public:
    AbstractHTTPClient(QObject* parent = 0) : QObject(parent) {}
    virtual ~AbstractHTTPClient() = default;

    virtual auto getServerCurrentTime() -> void = 0;
    virtual auto getServerUserList() -> void = 0;
    virtual auto postServerSendNewUser() -> void = 0;
    virtual auto deleteServerFirstUser() -> void = 0;

signals:
    auto serverCurrentTime(QString answer) -> void;
    auto serverUserList(QString answer) -> void;
    auto error(QString error) -> void;

};

} // namespace Network
