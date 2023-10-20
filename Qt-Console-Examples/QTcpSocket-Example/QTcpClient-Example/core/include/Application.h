#pragma once

#include <QApplication>
#include <QThread>

#include "AbstractSocket.h"

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    virtual ~Application();

    void launch();

private:
    Transport::AbstractSocket* socket;
    QThread* socketThread;

};
