#include "Server.h"

#include "Poco/Net/HTTPServer.h"
#include "RequestHandlerFactory.h"

#include <QDebug>

auto Server::main([[maybe_unused]] const std::vector<std::string>& args) -> int
{
    Poco::Net::HTTPServerParams* pParams = new Poco::Net::HTTPServerParams;

    pParams->setMaxQueued(100);
    pParams->setMaxThreads(16);

    Poco::Net::HTTPServer server(new RequestHandlerFactory, Poco::Net::ServerSocket(8000), pParams);

    server.start();
    qDebug() << "Server started";

    waitForTerminationRequest();  // wait for CTRL-C or kill

    qDebug() << "Shutting down...";
    server.stop();

    return Application::EXIT_OK;
}
