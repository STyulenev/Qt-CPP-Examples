cmake_minimum_required(VERSION 3.5)

project(Containers-examples-lib
    VERSION 0.1
    DESCRIPTION "Library with simple delegates"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

#set(BOOST_NO_SYSTEM_PATHS ON)
#set(BOOST_USE_MULTITHREADED ON)
#set(BOOST_USE_STATIC_LIBS ON)
#set(BOOST_USE_STATIC_RUNTIME ON)
#set(BOOST_ALL_DYN_LINK ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB src "include/*.h" "./*.cpp")

set(BOOST_ROOT "C:/boost_1_70_0") # Path to Boost

find_package(Boost 1.70 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

if(Boost_FOUND)
    add_library(${PROJECT_NAME} STATIC ${src})

    target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})

    target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        ${Boost_LIBRARIES}
    )

    target_include_directories(${PROJECT_NAME} PUBLIC include)
else()
    message(FATAL_ERROR "BOOST NOT FOUND")
endif ()






