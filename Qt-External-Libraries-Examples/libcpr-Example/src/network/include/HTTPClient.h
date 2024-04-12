#pragma once

#include "AbstractHTTPClient.h"

namespace Network {

class HTTPClient : public AbstractHTTPClient
{
public:
    HTTPClient(QObject* parent = 0);
    ~HTTPClient();

    auto getServerCurrentTime() -> void override;
    auto getServerUserList() -> QString override;
    auto postServerSendNewUser() -> QString override;
    auto deleteServerFirstUser() -> QString override;

};

} // namespace Network
