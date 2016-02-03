#pragma once

#include <QObject>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include "QQmlHelpers"

class Meal : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(int,author)
    QML_WRITABLE_PROPERTY(int,food)
    QML_WRITABLE_PROPERTY(QString, instant)
public:
    Meal();
    Meal(QString instant,int author,int food);

};
