QT += quick

CONFIG += c++20

TARGET = QML-SipeView-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

QML_IMPORT_PATH += $$PWD/qml

INCLUDEPATH += src/

HEADERS += \
        src/QuestionnaireModel.h

SOURCES += \
        main.cpp \
        src/QuestionnaireModel.cpp

RESOURCES += \
        qrc.qrc
