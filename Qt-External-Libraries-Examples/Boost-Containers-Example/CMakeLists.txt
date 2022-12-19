cmake_minimum_required(VERSION 3.5)

project(Boost-Containers-Example
    VERSION 0.1
    DESCRIPTION "Project with sample Boost containers and data structs Example"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
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

file(GLOB containers-examples-src "containers-examples/include/*.h" "containers-examples/*.cpp")

add_executable(${PROJECT_NAME}
    main.cpp

    ${containers-examples-src}
)

set(BOOST_ROOT "C:/boost_1_70_0") # Path to Boost

find_package(Boost 1.70 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        ${Boost_LIBRARIES}
        )
else()
    message(FATAL_ERROR "BOOST NOT FOUND")
endif ()
