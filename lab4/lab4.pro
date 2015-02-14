TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    car.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    car.h \
    task2.h

