#############################################################################
##
## Дополнительный pri файл для добавления внешней библиотеки LimeReport (https://github.com/fralx/LimeReport).
## Библиотека должна быть скомпилирована (release) как .dll (windows) или .so (linux).
## Путь до .dll необходимо установить в LIME_REPORT_DLL.
## Путь до include директории необходимо установить в LIME_REPORT_INCLUDE.
## Если пути не будут найдены, будет выведено сообщение об ошибке.
##
## Маркер LIME_REPORT необходим для того, чтобы в коде выделить место, где используется LimeReport.
##
#############################################################################

win32 {
    SHARED_DLL_PATH = "C:/Work/3rdparty/libs/" # Путь до .dll's

    LIME_REPORT_DLL     = "$$SHARED_DLL_PATH/liblimereport-qt6.dll"
    LIME_REPORT_INCLUDE = "C:/Work/3rdparty/include/LimeReport/include/"

    exists ($$LIME_REPORT_DLL) {
        LIBS    += -L$$SHARED_DLL_PATH -llimereport-qt6
        DEFINES += LIME_REPORT_DLL_EXISTS
        QT += xml qml printsupport
    } else {
        message("Error. Don't exists - liblimereport-qt6.dll in $$LIME_REPORT_PATH")
    }

    exists ($$LIME_REPORT_INCLUDE) {
        INCLUDEPATH += $$LIME_REPORT_INCLUDE
        DEFINES     += LIME_REPORT_INCLUDE_EXISTS
    } else {
        message("Error. Don't exists directory - $$LIME_REPORT_INCLUDE")
    }

    contains (DEFINES, LIME_REPORT_DLL_EXISTS) {
        contains (DEFINES, LIME_REPORT_INCLUDE_EXISTS) {
            DEFINES += LIME_REPORT
        }
    }
}

unix {
    message("Error. Unknown system.")
}
