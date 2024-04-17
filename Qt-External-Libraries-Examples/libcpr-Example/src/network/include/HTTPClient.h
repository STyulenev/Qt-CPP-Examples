#pragma once

#include "AbstractHTTPClient.h"

namespace Network {

class HTTPClient : public AbstractHTTPClient
{
public:
    HTTPClient(QObject* parent = 0);
    ~HTTPClient();

    auto getServerCurrentTime() -> void override;
    auto getServerUserList() -> void override;
    auto postServerSendNewUser() -> void override;
    auto deleteServerFirstUser() -> void override;

};

} // namespace Network
