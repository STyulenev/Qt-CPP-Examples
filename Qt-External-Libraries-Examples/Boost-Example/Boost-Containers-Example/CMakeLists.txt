cmake_minimum_required(VERSION 3.5)

project(Boost-Containers-Example
    VERSION 0.1
    DESCRIPTION "Project with sample Boost containers and data structs Example"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(BOOST_NO_SYSTEM_PATHS ON)
#set(BOOST_USE_MULTITHREADED ON)
#set(BOOST_USE_STATIC_LIBS ON)
#set(BOOST_USE_STATIC_RUNTIME OFF)
#set(BOOST_ALL_DYN_LINK OFF)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_subdirectory(src)

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
    Boost-Containers-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
