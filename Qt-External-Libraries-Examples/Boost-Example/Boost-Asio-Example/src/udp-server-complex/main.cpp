#include <iostream>

#include "udpserver.h"

int main()
{
    UdpServer server(8080);

    server.start();

    std::cout << "Press Enter to stop server..." << std::endl;
    std::cin.get();  // Ждём нажатия Enter

    server.stop();
    return 0;
}
