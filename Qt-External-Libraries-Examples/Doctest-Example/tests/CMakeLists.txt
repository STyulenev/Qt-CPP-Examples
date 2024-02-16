cmake_minimum_required(VERSION 3.14)

project(Test-bin
    VERSION 0.1
    DESCRIPTION "Binary with tests"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

if(NOT EXISTS "doctest.h")
    execute_process(COMMAND curl https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h -o doctest.h args
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)
endif()

add_executable(${PROJECT_NAME}
    doctest.h
    text_example.cpp
)

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Logic-lib
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
