#include "MainWindow.h"

#include "Application.h"

auto main(int argc, char* argv[]) -> int
{
    Application app(argc, argv);
    app.launch();

    Views::MainWindow w;
    w.show();

    return app.exec();
}
