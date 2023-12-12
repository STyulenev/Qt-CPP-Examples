#include "MainWindow.h"
#include "SplashScreen.h"

#include <QApplication>
#include <QThread>

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);
    Views::MainWindow w;

    Views::SplashScreen splashScreen;
    splashScreen.show();
    app.processEvents();
    {
        // some actions
        QThread::sleep(5);
    }
    splashScreen.finish(&w);

    w.show();
    return app.exec();
}
