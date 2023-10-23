cmake_minimum_required(VERSION 3.14)

project(QUdpSocket-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QUdpSocket (client and server)"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

add_subdirectory(QUdpServer-Example)
add_subdirectory(QUdpClient-Example)
