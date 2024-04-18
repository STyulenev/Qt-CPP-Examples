#pragma once

#include <QCoreApplication>
#include <QThread>

#include "HttpServer.h"

namespace Core {

class Application : public QCoreApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    virtual ~Application();

    auto launch() -> void;

private:
    Transport::HttpServer* server;
    QThread* serverThread;

};

} // namespace Core
