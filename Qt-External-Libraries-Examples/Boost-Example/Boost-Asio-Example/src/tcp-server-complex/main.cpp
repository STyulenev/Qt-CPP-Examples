#include "tcpserver.h"

#include <iostream>

int main()
{
    TcpServer server(8080);

    server.start(4);

    std::cout << "Press Enter to stop server..." << std::endl;
    std::cin.get();  // Ждём нажатия Enter

    server.stop();  // Блокирует до завершения потоков

    return 0;
}
