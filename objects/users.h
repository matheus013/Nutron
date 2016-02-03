#pragma once

#include <QObject>
#include "QQmlHelpers"

class Users : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int, id)
    QML_WRITABLE_PROPERTY(QString, username)
    QML_WRITABLE_PROPERTY(QString, password)
    QML_WRITABLE_PROPERTY(QString, name)
    QML_WRITABLE_PROPERTY(QString, email)
    QML_WRITABLE_PROPERTY(int, level)
    QML_WRITABLE_PROPERTY(int, age)
    QML_WRITABLE_PROPERTY(int, score)
    QML_WRITABLE_PROPERTY(double, height)
    QML_WRITABLE_PROPERTY(double, weight)

public:
    Users();
    Users(const QObject* object);
    Users(QString username, QString password, QString name, QString email,
          int age, double height, double weight);
    bool isEmpty();

};
