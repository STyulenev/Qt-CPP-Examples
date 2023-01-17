cmake_minimum_required(VERSION 3.5)

project(Boost-Algorithm-Example
    VERSION 0.1
    DESCRIPTION "Project with sample Boost Algorithm"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(BOOST_EXISTS ON)

add_executable(${PROJECT_NAME}
    SearchingAlgorithms.h
    SearchingAlgorithms.cpp
    main.cpp
)

if(BOOST_EXISTS) # If the boost library is on the local computer
    set(BOOST_ROOT "C:/3rdparty/boost_1_81_0") # Path to Boost

    find_package(Boost 1.81 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

    if(Boost_FOUND)
        target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})

        target_link_libraries(${PROJECT_NAME} PUBLIC
            Qt${QT_VERSION_MAJOR}::Core
            ${Boost_LIBRARIES}
        )

        target_include_directories(${PROJECT_NAME} PUBLIC include)
    else()
        message(FATAL_ERROR "BOOST NOT FOUND")
    endif ()
else() # If the boost library is missing
    set(BOOST_INCLUDE_LIBRARIES algorithm container)
    set(BOOST_ENABLE_CMAKE ON)

    include(FetchContent)
    FetchContent_Declare(
      Boost
      GIT_REPOSITORY https://github.com/boostorg/boost.git
      GIT_TAG boost-1.81.0
    )
    FetchContent_MakeAvailable(Boost)

    target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Boost::container
        Boost::algorithm
    )
endif()
