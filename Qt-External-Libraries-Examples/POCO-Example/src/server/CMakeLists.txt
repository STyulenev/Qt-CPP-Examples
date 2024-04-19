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
    # 
    #set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/3rdparty/poco-master")
    #set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/3rdparty/build-poco-master-Desktop_Qt_6_4_0_MSVC2019_64bit-Debug")
    #find_package(Poco 1.13.1 REQUIRED COMPONENTS Foundation Util Net XML JSON)
    #message("Poco_INCLUDE_DIRS = ${Poco_INCLUDE_DIRS}")
    #message("Poco_LIBRARIES = ${Poco_LIBRARIES}")

    include(FetchContent)
    FetchContent_Declare(
        Poco
        GIT_REPOSITORY https://github.com/pocoproject/poco.git
        GIT_TAG poco-1.13.1-release
    )
    FetchContent_MakeAvailable(Poco)
elseif()
    # ...
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
