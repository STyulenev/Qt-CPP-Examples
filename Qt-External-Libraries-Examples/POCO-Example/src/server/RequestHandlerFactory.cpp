#include "RequestHandlerFactory.h"

#include "ErrorHandler.h"
#include "TimeHandler.h"
#include "UsersHandler.h"

#include <Poco/URI.h>
#include <QDebug>

auto RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request) -> Poco::Net::HTTPRequestHandler*
{
    qDebug() << "myapi = " << request.getURI().c_str();

    if (!request.getURI().find("/time")) {
        return new Handlers::TimeHandler();
    } else if (!request.getURI().find("/users")) {
        return new Handlers::UsersHandler();
    } else {
        return new Handlers::ErrorHandler(); // or return nullptr;
    }
}
