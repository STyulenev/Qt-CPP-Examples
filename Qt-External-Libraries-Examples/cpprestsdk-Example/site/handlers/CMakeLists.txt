cmake_minimum_required(VERSION 3.16)

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/handlers.h)

add_subdirectory(src)

