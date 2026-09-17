#include "tcpclient.h"

#include <iostream>

int main()
{
    {
        TcpClient client;

        if (!client.connectSync("127.0.0.1", "8080"))
        {
            return 1;
        }

        std::cout << "Enter message: ";
        char request[1024];
        std::cin.getline(request, 1024);
        std::string message(request);
        message.push_back('\n');

        client.sendSync(message);

        std::string reply = client.receiveUntil("\n");
        std::cout << "Server replied: " << reply;

        client.stop();
    }

    return 0;
}
