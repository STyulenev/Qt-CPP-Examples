#include "RequestHandlerFactory.h"

#include "ErrorHandler.h"
#include "TimeHandler.h"

#include <Poco/URI.h>
#include <QDebug>

auto RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request) -> Poco::Net::HTTPRequestHandler*
{
    if (!request.getURI().find("/time")) {
        qDebug() << "myapi = " << request.getURI().c_str();
        return new Handlers::TimeHandler();
    } else {
        qDebug() << "myapi = " << request.getURI().c_str();
        return new Handlers::ErrorHandler(); // or return nullptr;
    }
}
