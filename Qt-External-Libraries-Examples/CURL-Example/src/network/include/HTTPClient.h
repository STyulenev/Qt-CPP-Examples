#pragma once

#include <QString>

class HTTPClient
{
private:
    static HTTPClient* self;

    HTTPClient();
    HTTPClient(const HTTPClient&);
    auto operator=(HTTPClient&) -> HTTPClient&;

public:
    static HTTPClient* getClient();

    auto getServerCurrentTime() -> QString;

};
