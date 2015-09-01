TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp \
    circularly_list.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    student.h \
    circularly_list.h

