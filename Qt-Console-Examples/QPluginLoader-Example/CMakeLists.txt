cmake_minimum_required(VERSION 3.16)

project(QPluginLoader-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QPluginLoader"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Qml Quick REQUIRED)

set(PROJECT_SOURCES
    main.cpp

    PluginController.h
    PluginController.cpp

    ./include/IPlugin.h

    resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(${PROJECT_NAME}
       ${PROJECT_SOURCES}
    )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    "./include"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
)
