cmake_minimum_required(VERSION 3.5)

project(cpack-lib
    VERSION 0.5
    DESCRIPTION "CPack library example"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB cpack-lib-include "include/*.h")
file(GLOB cpack-lib-src "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${cpack-lib-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    ./include
)

configure_file(cpack-lib.cmake.in "${PROJECT_BINARY_DIR}/cpack-libConfig.cmake" @ONLY)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cpack-libConfig.cmake"
    DESTINATION "${LIBRARY_DESTINATION}/cmake/${PROJECT_NAME}"
    PERMISSIONS ${DOC_PERMISSIONS_DEFAULT}
    COMPONENT runtime
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION "${LIBRARY_DESTINATION}"
    PERMISSIONS ${LIB_PERMISSIONS_DEFAULT}
    COMPONENT runtime
)

install(FILES ${cpack-lib-include}
    DESTINATION "${INCLUDES_INSTALL_DIR}/cpack-lib"
    PERMISSIONS ${INCLUDE_PERMISSIONS_DEFAULT}
    COMPONENT runtime
)
