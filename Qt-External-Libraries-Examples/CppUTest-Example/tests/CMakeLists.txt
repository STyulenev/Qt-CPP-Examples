cmake_minimum_required(VERSION 3.1)

project(CppUTest-bin
    VERSION 0.1
    DESCRIPTION "Directory for CppUTests"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

file(GLOB test-src "./*.cpp")

add_executable(${PROJECT_NAME} ${test-src})

set(CPPUTEST_LINK "static") # Типы подключения: static / conan / fetch / ... (другой)
#set(CPPUTEST_LINK "static" CACHE STRING "where will the CppUTest library be linked from?")
#set_property(CACHE CPPUTEST_LINK PROPERTY STRINGS other static conan fetch)

if("${CPPUTEST_LINK}" STREQUAL "static")
    # git clone https://github.com/cpputest/cpputest.git
    # cd cpputest-master/build
    # cmake ..
    # make
    message("static link")

    target_include_directories(${PROJECT_NAME} PRIVATE "C:/3rdparty/cpputest-master/include")
    target_link_libraries(${PROJECT_NAME} PRIVATE
        Logic-lib
        "C:/3rdparty/cpputest-master/build/src/CppUTest/libCppUTest.a"
        # ...
    )
elseif("${CPPUTEST_LINK}" STREQUAL "conan")
    # conan install . --output-folder=build --build=missing
    message("conan link")

    find_package(CppUTest 4.0 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        Logic-lib
        ${CppUTest_LIBRARIES}
    )
elseif("${CPPUTEST_LINK}" STREQUAL "fetch")
    # need remove conanfile.txt
    message("fetch link")

    # CppUTest
    include(FetchContent)
    FetchContent_Declare(
        CppUTest
        GIT_REPOSITORY https://github.com/cpputest/cpputest.git
        GIT_TAG        master # or use release tag, eg. v4.0
    )
    # Set this to ON if you want to have the CppUTests in your project as well.
    set(TESTS ON CACHE BOOL "Switch off CppUTest Test build")
    FetchContent_MakeAvailable(CppUTest)

    target_link_libraries(${PROJECT_NAME} PRIVATE
        Logic-lib
        CppUTest::CppUTest
        CppUTest::CppUTestExt
    )
elseif()
    message(FATAL_ERROR "unknown link")
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
