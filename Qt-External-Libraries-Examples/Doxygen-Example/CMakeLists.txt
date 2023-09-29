cmake_minimum_required(VERSION 3.5)

project(Doxygen-Example
    VERSION 0.1
    DESCRIPTION "Doxygen-Example"
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(src)

set(PROJECT_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}   
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Widgets
    View-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_subdirectory(docs)

