cmake_minimum_required(VERSION 3.14)

project(QML-SystemTrayIcon
    VERSION 0.1
    DESCRIPTION "Project with sample QML-SystemTrayIcon"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick QuickWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickWidgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    resources.qrc
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

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickWidgets
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
