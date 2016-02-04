QT += core sql quick
QT -= gui

CONFIG += c++11

TARGET = AutoBuildSQL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bd/connection.cpp \
    bd/database.cpp \
    bd/tablemanagement.cpp \
    bd/daobject.cpp \
    objects/users.cpp \
    objects/food.cpp \
    system/terminal.cpp \
    system/authenticate.cpp \
    objects/meal.cpp \
    system/action.cpp \
    assets/cpp/qqmlobjectlistmodel.cpp

HEADERS += \
    bd/connection.h \
    bd/database.h \
    bd/tablemanagement.h \
    bd/daobject.h \
    objects/users.h \
    objects/food.h \
    system/terminal.h \
    system/authenticate.h \
    objects/meal.h \
    system/action.h \
    assets/cpp/qqmlobjectlistmodel.h

RESOURCES += \
    qrc.qrc
