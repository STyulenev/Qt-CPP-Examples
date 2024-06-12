cmake_minimum_required(VERSION 3.5)

project(QtUiPlugin-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QtUiPlugin"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets UiPlugin)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets UiPlugin)

include_directories("./Widgets")

file(GLOB plugins-src "Plugins/*.h" "Plugins/*.cpp")
file(GLOB widgets-src "Widgets/*.h" "Widgets/*.cpp")

include_directories("Widgets" "Plugins")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(${PROJECT_NAME} SHARED
        ${plugins-src}
        ${widgets-src}

        MyPlugins.cpp
        MyPlugins.h
    )
else()
    add_library(${PROJECT_NAME} SHARED
        ${plugins-src}
        ${widgets-src}

        MyPlugins.cpp
        MyPlugins.h
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::UiPlugin
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(UNIX)
    install(
        TARGETS ${PROJECT_NAME}
        DESTINATION "/usr/lib/x86_64-linux-gnu/qt5/plugins/designer" # для x86
    )

    install(
        FILES ${widgets-src}
        DESTINATION "/usr/include/x86_64-linux-gnu/qt5/QtUiPlugin" # для x86
    )
elseif(APPLE)
   # ...
elseif(WIN32)
   # ...
endif()
