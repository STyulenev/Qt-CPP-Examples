cmake_minimum_required(VERSION 3.5)

project(Network-lib
    VERSION 0.1
    DESCRIPTION "Network"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

if(WIN32)
    set(cpr_LIBRARY "C:/3rdparty/libcpr/build/install/bin")
    list(APPEND CMAKE_PREFIX_PATH "C:/3rdparty/libcpr/cmake")
    set(cpr_INCLUDE_DIR "C:/3rdparty/libcpr/build/install/include")

    #find_package(cpr REQUIRED)

    if(cpr_FOUND)
        message("CURL was found ${cpr_LIBRARIES} ${cpr_LIBRARY}")
    elseif()
        message(FATAL_ERROR "CURL not found")
    endif()
endif()

file(GLOB network-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${network-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    "C:/3rdparty/libcpr/build/install/include"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core

    "C:/3rdparty/libcpr/build/install/bin/libcurl.dll"
    "C:/3rdparty/libcpr/build/install/bin/libcpr.dll"
    "C:/3rdparty/libcpr/build/install/bin/libzlib.dll"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
