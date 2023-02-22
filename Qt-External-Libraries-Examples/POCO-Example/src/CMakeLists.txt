cmake_minimum_required(VERSION 3.5)

project(POCO-Example-server
    VERSION 0.1
    DESCRIPTION "Library with server"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

if(WIN32)
    if(MSVC) # WIN32
        # If paths to environment variables are not added
        set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/3rdparty/poco-master")
        set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/3rdparty/build-poco-master-Desktop_Qt_6_4_0_MSVC2019_64bit-Debug")

        # Find Poco package 1.12.4
        find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON)
        message("Poco_INCLUDE_DIRS = ${Poco_INCLUDE_DIRS}")
        message("Poco_LIBRARIES = ${Poco_LIBRARIES}")
    elseif(MINGW)
        message(FATAL_ERROR "Qt + POCO + MinGW not work")
    else()
        message(FATAL_ERROR "Unknown compiler. Settings needed.")
    endif(MSVC)
endif(WIN32)

file(GLOB server-src "include/*.h" "./*.cpp")
file(GLOB handlers-src "handlers/include/*.h" "handlers/*.cpp")

add_library(${PROJECT_NAME} STATIC ${server-src} ${handlers-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core

    Poco::Foundation
    Poco::Net
    Poco::Util
    Poco::XML
    Poco::JSON
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
