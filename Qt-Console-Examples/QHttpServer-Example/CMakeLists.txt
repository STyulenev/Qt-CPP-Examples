cmake_minimum_required(VERSION 3.14)

project(QHttpServer-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QHttpServer"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network HttpServer REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network HttpServer REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    userlist.h
    userlist.cpp
)

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::HttpServer
)
