QT += core sql quick
QT -= gui

CONFIG += c++11

TARGET = AutoBuildSQL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    connection.cpp \
    database.cpp \
    tablemanagement.cpp \
    daobject.cpp \
    users.cpp \
    food.cpp \
    terminal.cpp \
    authenticate.cpp \
    meal.cpp

HEADERS += \
    connection.h \
    database.h \
    tablemanagement.h \
    daobject.h \
    users.h \
    food.h \
    terminal.h \
    authenticate.h \
    meal.h
