#include "Server.h"

#include "Poco/Net/HTTPServer.h"
#include "RequestHandlerFactory.h"

#include <QDebug>

auto Server::main([[maybe_unused]] const std::vector<std::string>& args) -> int
{
    Poco::Net::HTTPServerParams* serverParams = new Poco::Net::HTTPServerParams;

    serverParams->setMaxQueued(100);
    serverParams->setMaxThreads(16);

    Poco::Net::HTTPServer server(new RequestHandlerFactory, Poco::Net::ServerSocket(8000), serverParams);

    server.start();
    qDebug() << "Server started";

    waitForTerminationRequest();  // wait for CTRL-C or kill

    qDebug() << "Shutting down...";
    server.stop();

    return Application::EXIT_OK;
}
