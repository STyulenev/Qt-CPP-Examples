#pragma once

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/URI.h>

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    virtual auto createRequestHandler(const Poco::Net::HTTPServerRequest& request) -> Poco::Net::HTTPRequestHandler* override;
};
