cmake_minimum_required(VERSION 3.5)

project(QML-TableView-Delegates-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QML-TableView and delegates"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    TableModel.h
    TableModel.cpp

    qrc.qrc
)

#list(APPEND QML_IMPORT_PATH "${CMAKE_SOURCE_DIR}/qml/Widgets")
list(APPEND QML_IMPORT_PATH "${CMAKE_SOURCE_DIR}/qml/Widgets")
list(REMOVE_DUPLICATES QML_IMPORT_PATH)
set(QML2_IMPORT_PATH ${QML_IMPORT_PATH} CACHE STRING "QML import paths" FORCE)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick)
