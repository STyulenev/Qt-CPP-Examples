#pragma once

#include <QCoreApplication>
#include <QThread>

#include "AbstractServer.h"

class Application : public QCoreApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    virtual ~Application();

    void launch();

private:
    Transport::AbstractServer* server;
    QThread* serverThread;

};
