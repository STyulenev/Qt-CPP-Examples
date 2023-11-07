#include "MainWindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Views::MainWindow w;
    w.show();

    return app.exec();
}
