TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    my_list.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    my_list.h

