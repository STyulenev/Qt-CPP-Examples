TARGET = ru.template.Aurora-Pickers-Example

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \

HEADERS += \

DISTFILES += \
    rpm/ru.template.Aurora-Pickers-Example.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.Aurora-Pickers-Example.ts \
    translations/ru.template.Aurora-Pickers-Example-ru.ts \
