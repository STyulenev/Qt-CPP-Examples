cmake_minimum_required(VERSION 3.5)

project(QxORM-Example-view-model
    VERSION 0.1
    DESCRIPTION "View model"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB view-model-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${view-model-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    QxORM-Example-dao
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
