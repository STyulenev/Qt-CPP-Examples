#include "Application.h"

int main(int argc, char* argv[])
{
    Application app(argc, argv);
    app.launch();

    return app.exec();
}
