#pragma once

#include <QObject>
#include "QQmlHelpers"

class User : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int, user_id)
    QML_WRITABLE_PROPERTY(QString, username)
    QML_WRITABLE_PROPERTY(QString, password)
    QML_WRITABLE_PROPERTY(QString, email)
    QML_WRITABLE_PROPERTY(QString, photo)
    QML_WRITABLE_PROPERTY(QString, name)
    QML_WRITABLE_PROPERTY(int, level)
    QML_WRITABLE_PROPERTY(int, age)
    QML_WRITABLE_PROPERTY(int, score)
    QML_WRITABLE_PROPERTY(double, height)
    QML_WRITABLE_PROPERTY(double, weight)

public:
    User();
    User(const QObject* object);
    User(QString username, QString password, QString name, QString email,
          int age, double height, double weight);
    bool isEmpty();

};
