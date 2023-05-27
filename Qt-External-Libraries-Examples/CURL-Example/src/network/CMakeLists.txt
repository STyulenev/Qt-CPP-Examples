cmake_minimum_required(VERSION 3.5)

project(Network-lib
    VERSION 0.1
    DESCRIPTION "Network"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

if(WIN32)
    set(CURL_LIBRARY "C:/3rdparty/curl-master/build/lib")
    set(CURL_INCLUDE_DIR "C:/3rdparty/curl-master/include")

    find_package(CURL REQUIRED)

    if(CURL_FOUND)
        message("CURL was found ${CURL_LIBRARIES} ${CURL_LIBRARY}")
        include_directories(${CURL_INCLUDE_DIR})
    elseif()
        message(FATAL_ERROR "CURL not found")
    endif()
endif()

file(GLOB network-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${network-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    "C:/3rdparty/curl-master/build/lib/libcurl.dll"
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
