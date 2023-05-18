#pragma once

#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class HTTPClient
{
private:
    static HTTPClient* self;

    HTTPClient();
    ~HTTPClient();

    HTTPClient(const HTTPClient&);
    auto operator=(HTTPClient&) -> HTTPClient&;

public:
    static HTTPClient* getClient();

    auto getServerCurrentTime() -> QString;

    auto getServerUserList() -> void;

    auto postServerSendNewUser() -> void;

};
