cmake_minimum_required(VERSION 3.16)

project(Qml-plugin-lib
    VERSION 0.1
    DESCRIPTION "Static library for new Qml plugin"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Gui Qml Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui Qml Quick REQUIRED)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt6_policy(SET QTP0001 NEW)
    qt6_add_qml_module(uilibplugin
        URI "uilib"
        PLUGIN_TARGET uilibplugin
        DEPENDENCIES QtQuick
        QML_FILES MyTest.qml
    )

    target_sources(uilibplugin PRIVATE
        MyRectangle.h
        MyRectangle.cpp
        qmldir
    )
else()
    # ...
endif()


target_link_libraries(uilibplugin PRIVATE
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
)

set(INSTALL_DIR "${CMAKE_BINARY_DIR}/plugin/uilib")

install(TARGETS uilibplugin
    RUNTIME DESTINATION "${INSTALL_DIR}"
    BUNDLE DESTINATION "${INSTALL_DIR}"
    LIBRARY DESTINATION "${INSTALL_DIR}"
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/qmldir
    DESTINATION "${INSTALL_DIR}"
)
