#include "webserver.h"

#include <iostream>

int main()
{
    WebServer server(8080);

    server.start();  // Запуск в фоне, главный поток свободен

    std::cout << "Press Enter to stop server..." << std::endl;
    std::cin.get();  // Ждём нажатия Enter

    server.stop();   // Корректная остановка

    return 0;
}
