#include "RequestHandlerFactory.h"

#include "../handlers/include/MyHandler.h"

#include <QDebug>

auto RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request) -> Poco::Net::HTTPRequestHandler*
{
    if (!request.getURI().find("/myapi/")) {
        qDebug() << "myapi = " << request.getURI().c_str();
        return new MyHandler;
    } else {
        qDebug() << "myapi = " << request.getURI().c_str();
        return nullptr;
    }
}
