#pragma once

#include <QObject>
#include "assets/cpp/qqmlobjectlistmodel.h"
#include "objects/users.h"

class Authenticate : public QObject {
    Q_OBJECT
    QQmlObjectListModel<User> * model;
public:
    Authenticate(QQmlObjectListModel<User> * model);
    Q_INVOKABLE bool isEmailAddress(QString email);
    bool loginIsValid(QString username,QString password);
    Q_INVOKABLE bool usernameValid(QString username);
    Q_INVOKABLE bool emailValid(QString email);

};

