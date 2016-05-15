##########################################################################
# qmake .pro file to build GTK+ 3.0 project
# -----------------------------------------------------------------------
# Copyright 2016 Laurent LAMARD
#
##########################################################################

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#set to use gcc in place g++ to link
# we use c not c++
QMAKE_LINK = gcc
QMAKE_CC = gcc

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = build/release
}

# set output build files
OBJECTS_DIR = $$DESTDIR

# setup compile flags
QMAKE_CFLAGS_WARN_ON -= -W -Wno-unused-variable
QMAKE_CFLAGS += -std=c11 -Wimplicit-function-declaration
QMAKE_CFLAGS_RELEASE += -march=native -mtune=native -std=c11
QMAKE_LFLAGS_RELEASE += -s 

unix: CONFIG	+= link_pkgconfig
unix: PKGCONFIG += gtk+-3.0

# sources files
SOURCES += \   
    main.c \
    exampleapp.c \    
    exampleappwin.c

# headers files
HEADERS += \
    exampleappwin.h \
    exampleapp.h

# resources files
RESOURCES = exampleapp.gresource.xml


# part to compile and build GTK+ 3 resources files
gtk_resources.input = RESOURCES
gtk_resources.output = $$DESTDIR/resources.c
gtk_resources.commands = glib-compile-resources ${QMAKE_FILE_NAME} --target=${QMAKE_FILE_OUT} --sourcedir=$${PWD} --generate-source
gtk_resources.variable_out = SOURCES
QMAKE_EXTRA_COMPILERS += gtk_resources

FORMS += \
    menu.ui \
    window.ui
