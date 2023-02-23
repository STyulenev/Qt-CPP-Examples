TEMPLATE = subdirs

SUBDIRS = \
    ProjectOne/StaticLibrary \
    SharedLibrary \
    ProjectOne \
    ProjectTwo \   

ProjectOne.depends = StaticLibrary SharedLibrary
ProjectTwo.depends = SharedLibrary

