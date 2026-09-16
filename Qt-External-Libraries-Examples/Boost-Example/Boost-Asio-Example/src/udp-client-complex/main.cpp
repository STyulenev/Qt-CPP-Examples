#include <iostream>

#include "udpclient.h"

int main()
{
    UdpClient client("127.0.0.1", "8080");

    client.set_on_reply([](const std::string& reply) {
        std::cout << "Client received: " << reply << std::endl;
    });

    char request[1024];
    std::cout << "Enter message: ";
    std::cin.getline(request, 1024);

    client.send(request);
    client.wait();  // Ждём ответа

    return 0;
}
