#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <QObject>

class Authenticate : public QObject {
    Q_OBJECT
public:
    Authenticate();
    bool isEmailAddress(QString email);
    bool loginIsValid(QString username,QString password);
    bool usernameExists(QString username);

};

#endif // AUTHENTICATE_H
