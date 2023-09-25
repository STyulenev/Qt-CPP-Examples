cmake_minimum_required(VERSION 3.5)

project(QFileSystemWatcher-Example LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -Wno-deprecated-declarations -fstrict-aliasing -pedantic-errors -Wno-unused-variable")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Setting-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
