QT += quick

CONFIG += c++20

TARGET = QML-Style-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

QML_IMPORT_PATH += \
		$$PWD/qml \
		$$PWD/qml/CustomStyle

SOURCES += \
        main.cpp

RESOURCES += \
        resource.qrc
