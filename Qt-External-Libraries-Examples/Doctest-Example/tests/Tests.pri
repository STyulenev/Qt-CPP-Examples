INCLUDEPATH += \
        $$PWD

SOURCES += \
        $$files($$PWD/*.cpp)

win32 { ## Windows common build here
    !exists ($$PWD/doctest.h) {
        system("cd $$PWD && curl https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h -o doctest.h args")

        exists ($$PWD/doctest.h) {
            INCLUDEPATH += $$PWD/doctest.h
        } else {
            message("Error. Don't exists doctest.h")
        }
    }
} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
