cmake_minimum_required(VERSION 3.13)

project(QML-CircularGauge-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QML-CircularGauge (QtQuick.Extras library)"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    resource.qrc
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

# Register QML import paths for code completion
list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/qml")
list(REMOVE_DUPLICATES QML_DIRS)
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "QML import paths")

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Quick
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)