QT += core
QT -= gui

CONFIG += c++11

TARGET = pylib
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lpython2.7 -lboost_python
INCLUDEPATH += /usr/include/python2.7/

SOURCES += main.cpp \
    pyWrapper.cpp

HEADERS += \
    Plugin.h \
    pyWrapper.h
