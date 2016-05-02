QT += core sql quick
QT -= gui

CONFIG += c++11

TARGET = Nutron
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    objects/users.cpp \
    objects/food.cpp \
    system/terminal.cpp \
    system/authenticate.cpp \
    objects/meal.cpp \
    assets/cpp/qqmlobjectlistmodel.cpp \
    bd/webmanager.cpp

HEADERS += \
    objects/users.h \
    objects/food.h \
    system/terminal.h \
    system/authenticate.h \
    objects/meal.h \
    system/action.h \
    assets/cpp/qqmlobjectlistmodel.h \
    bd/webmanager.h

RESOURCES += \
    qrc.qrc \
    img.qrc
