#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <QObject>

class Authenticate : public QObject {
    Q_OBJECT
public:
    Authenticate();
    Q_INVOKABLE bool isEmailAddress(QString email);
    bool loginIsValid(QString username,QString password);
    Q_INVOKABLE bool usernameValid(QString username);
    Q_INVOKABLE bool emailValid(QString email);

};

#endif // AUTHENTICATE_H
