cmake_minimum_required(VERSION 3.14)

project(libharu-Example
    VERSION 0.1
    DESCRIPTION "Project with an example of using Qt and libharu"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -Wno-deprecated-declarations -fstrict-aliasing -pedantic-errors -Wno-unused-variable")

#Для корректного поиска файлов FindXXX.cmake добавляем директорию сборки в MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(libharu 2.4.6 REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    PDFCreator.cpp
    PDFCreator.h
    Model.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CONAN_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    libharu::libharu
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
