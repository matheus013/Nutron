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
    QML_WRITABLE_PROPERTY(int, height)
    QML_WRITABLE_PROPERTY(int, weight)

    QML_WRITABLE_PROPERTY(bool, hypertension)
    QML_WRITABLE_PROPERTY(bool, diabetes)
    QML_WRITABLE_PROPERTY(bool, anemia)
    QML_WRITABLE_PROPERTY(bool, high_cholesterol)

public:
    User();
    User(const QObject* object);
    User(QJsonObject obj);
    User(QString username, QString password, QString name, QString email,
          int age, int height, int weight);
    QString post();

};
