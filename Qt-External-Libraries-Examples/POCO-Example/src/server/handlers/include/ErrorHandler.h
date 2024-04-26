#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace Handlers {

class ErrorHandler : public Poco::Net::HTTPRequestHandler
{

public:
    auto handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& responce) -> void;

};

} //namespace Handlers
