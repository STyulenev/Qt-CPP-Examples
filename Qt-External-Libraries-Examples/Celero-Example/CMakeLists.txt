cmake_minimum_required(VERSION 3.15)

project(Celero-Example
    VERSION 0.1
    DESCRIPTION "Test project with an example of using the testing library Celero"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

option(TEST_OPTION "test opiton" ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_subdirectory(src)

if (NOT TEST_OPTION)
    message(STATUS "Tests disabled")
else()
    add_subdirectory(tests)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        main.cpp
    )
else()
    add_executable(${PROJECT_NAME}
        main.cpp
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Logic-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
