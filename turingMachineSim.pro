TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tm.cpp \
    state.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tm.h \
    state.h

