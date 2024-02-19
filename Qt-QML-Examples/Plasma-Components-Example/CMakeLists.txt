cmake_minimum_required(VERSION 3.0)

project(Plasma-Components-Example
    VERSION 0.1
    DESCRIPTION "Examples of QML components in KDE Plasma"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Gui Qml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui Qml REQUIRED)
find_package(KF5Plasma REQUIRED)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_resources(res-src resources.qrc)

    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        main.cpp
        ${res-src}
    )
else()
    qt5_add_resources(res-src resources.qrc)

    add_executable(${PROJECT_NAME}
        main.cpp
        ${res-src}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Gui
    KF5Plasma
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
