#pragma once
#include <QObject>
#include <QQmlHelpers>


class Person : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(QString,name)
    QML_WRITABLE_PROPERTY(int,age)
    QML_WRITABLE_PROPERTY(int,score)
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(double,height)
    QML_WRITABLE_PROPERTY(double,weight)
public:
     Person();
     Person(QString name, int age, double height, double weight, int score = 0);
     QString toInsert();
     QString toUpdate();

};

