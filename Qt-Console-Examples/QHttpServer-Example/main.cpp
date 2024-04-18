#include "Application.h"

auto main(int argc, char* argv[]) -> int
{
    Core::Application app(argc, argv);
    app.launch();
    return app.exec();
}
