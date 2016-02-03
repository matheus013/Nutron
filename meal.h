#pragma once

#include <QObject>
#include "QQmlHelpers"



class Meal : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(int,author)
    QML_WRITABLE_PROPERTY(int,food)
public:
    Meal();

};
