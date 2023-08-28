cmake_minimum_required(VERSION 3.5)

project(QML-Image-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QML-Image"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp

    QIconImage.h
    QIconImage.cpp

    ImageProvider.h
    ImageProvider.cpp

    resource.qrc
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
