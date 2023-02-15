#############################################################################
##
## Дополнительный cmake файл для добавления внешней библиотеки LimeReport (https://github.com/fralx/LimeReport).
##
## 1 - Как динамическая библиотека:
## Библиотека должна быть скомпилирована (release) как .dll (windows) или .so (linux).
## Путь до .dll необходимо установить в LIME_REPORT_DLL.
## Путь до include директории необходимо установить в LIME_REPORT_INCLUDE.
##
## 2 - Как статическая библиотека:
## Необходимо добавить папку проекта в текущую директорию
##
## 3 - Как статическая библиотека через FetchContent:
## Установить sha последнего коммита для загрузки из git.
##
#############################################################################

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Sql Network Xml Svg Quick PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql Network Xml Svg Quick PrintSupport REQUIRED)

set(LIME_REPORT_DLL "C:/Work/3rdparty/libs/liblimereport-qt6.dll")
set(LIME_REPORT_INCLUDE "C:/Work/3rdparty/include/LimeReport/include")

if(EXISTS ${LIME_REPORT_DLL} AND IS_DIRECTORY ${LIME_REPORT_INCLUDE}) # as dynamyc lib
    message("LimeReport dll was find")

    include_directories(${LIME_REPORT_INCLUDE})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${LIME_REPORT_DLL})
elseif(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/LimeReport") # as static lib
    message("LimeReport subdirectory was find")

    add_subdirectory(LimeReport)
    target_link_libraries(${PROJECT_NAME} PUBLIC limereport-qt${QT_VERSION_MAJOR})
else() # download and build as static lib
    include(FetchContent)
    FetchContent_Declare(
        LimeReport
        GIT_REPOSITORY https://github.com/fralx/LimeReport.git
        GIT_TAG        sha-of-the-commit # last comit needed
        )
    FetchContent_MakeAvailable(LimeReport)
    target_link_libraries(${PROJECT_NAME} PUBLIC limereport-qt${QT_VERSION_MAJOR})
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Xml
    Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Svg
    )
