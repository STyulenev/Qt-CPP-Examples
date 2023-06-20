cmake_minimum_required(VERSION 3.5)

project(QML-ListView-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QML-ListView"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

include_directories(${PROJECT_NAME} PRIVATE "src/")

add_executable(${PROJECT_NAME}
    main.cpp

    resource.qrc

    src/ListModel.h
    src/ListModel.cpp
)

list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/qml")
list(REMOVE_DUPLICATES QML_DIRS)
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "QML import paths")

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
