cmake_minimum_required(VERSION 3.5)

project(QtUiPlugin-Example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets UiPlugin REQUIRED)

include_directories("/home/vboxuser/Tests/QtUiPlugin-Example/Widgets")

file(GLOB plugins-src "Plugins/*.h" "Plugins/*.cpp")
file(GLOB widgets-src "Widgets/*.h" "Widgets/*.cpp")

include_directories("Widgets" "Plugins")

add_library(${PROJECT_NAME} SHARED
    ${plugins-src}
    ${widgets-src}
    
    MyPlugins.cpp
    MyPlugins.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Widgets
    Qt5::UiPlugin
)
