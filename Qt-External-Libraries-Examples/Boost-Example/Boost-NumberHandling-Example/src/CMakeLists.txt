cmake_minimum_required(VERSION 3.5)

project(Boost-NumberHandling-lib
    VERSION 0.1
    DESCRIPTION "The examples of using Number Handling from the boost library"
    LANGUAGES CXX
)

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

add_library(${PROJECT_NAME} STATIC ${src})

set(BOOST_EXISTS ON)

if(BOOST_EXISTS) # If the boost library is on the local computer
    if(WIN32)
        set(BOOST_ROOT "C:/3rdparty/boost_1_85_0") # Path to Boost

        # compiler check
        if (MSVC)
            message(FATAL_ERROR "Error. There is no boost library for this compiler on the current OS")
        elseif(MINGW) # I only have a compiled boost for windows
            message("OK. There is boost library for MinGW compiler on the current OS")
        else()
            message(FATAL_ERROR "Error. There is no boost library for this compiler on the current OS")
        endif (MSVC)
    endif(WIN32)

    find_package(Boost 1.85 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

    if(Boost_FOUND)
        target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})

        target_link_libraries(${PROJECT_NAME} PUBLIC
            Qt${QT_VERSION_MAJOR}::Core
            ${Boost_LIBRARIES}
            )

        target_include_directories(${PROJECT_NAME} PUBLIC include)
    else() # If the boost library is missing than get it from github
        message(FATAL_ERROR "Error. There are no boost library")
    endif()
elseif()
    set(BOOST_INCLUDE_LIBRARIES string) # add modules
    set(BOOST_ENABLE_CMAKE ON)

    include(FetchContent)
    FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.85.0
        )
    FetchContent_MakeAvailable(Boost)

    target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Boost::string
        # ...
        )
endif()
