#include "MainWindow.h"

#include "Application.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    app.launch();

    Views::MainWindow w;
    w.show();

    return app.exec();
}
