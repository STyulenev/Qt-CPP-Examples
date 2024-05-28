cmake_minimum_required(VERSION 3.5)

project(Controller-lib
    VERSION 0.1
    DESCRIPTION "Static library with controllers"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core DBus REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core DBus REQUIRED)

file(GLOB controller-src "include/*.h" "./*.cpp")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    set(dbus-src)

    qt6_add_dbus_adaptor(dbus-src
        org.example.message.xml
        qobject.h
        QObject
        message_adaptor
    )

    qt_add_library(${PROJECT_NAME} STATIC ${dbus-src} ${controller-src})
else()
    set(dbus-src)

    qt5_add_dbus_adaptor(dbus-src
        org.example.message.xml
        qobject.h
        QObject
        message_adaptor
    )

    add_library(${PROJECT_NAME} STATIC ${dbus-src} ${controller-src})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${CMAKE_BINARY_DIR}/src/controller
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::DBus
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
