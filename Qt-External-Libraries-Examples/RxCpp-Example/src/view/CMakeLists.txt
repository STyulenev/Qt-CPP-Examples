cmake_minimum_required(VERSION 3.5)

project(View-lib
    VERSION 0.1
    DESCRIPTION "Static library for View (forms)"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/3rdparty/RxCpp/build/lib")
    set(RxCpp_INCLUDE_DIR "C:/3rdparty/RxCpp/build/lib/include")

    find_package(RxCpp) # REQUIRED

    if (RxCpp_FOUND)
        message("-- rxcpp ${RxCpp_VERSION} found")
    else()
        message(FATAL_ERROR "-- RxCpp not found")
    endif()
elseif()
    message(FATAL_ERROR "Needed setting for current OS")
endif(WIN32)

file(GLOB view-src "include/*.h" "*.cpp" "ui/*.ui")

add_library(${PROJECT_NAME} STATIC ${view-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${RxCpp_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    Model-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
