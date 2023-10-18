cmake_minimum_required(VERSION 3.5)

project(QTcpSocket-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QTcpSocket (client and server)"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

add_subdirectory(QTcpServer-Example)
add_subdirectory(QTcpClient-Example)
