#pragma once

#include <Poco/Mutex.h>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
//#include <Poco/Net/HTTPServer.h>
//#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <Poco/Path.h>
//#include <Poco/ScopedLock.h>

#include <Poco/URI.h>
//#include <Poco/Util/ServerApplication.h>

//#include <Poco/Net/HTMLForm.h>
//#include <Poco/StringTokenizer.h>

class MyHandler : public Poco::Net::HTTPRequestHandler
{
/// static Poco::Mutex todoLock;
public:
    virtual auto handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp) -> void override;
};
