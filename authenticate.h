#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <QObject>

class Authenticate : public QObject {
    Q_OBJECT
public:
    Authenticate();
    bool isEmailAddress(QString email);
    bool loginIsValid(QString username,QString password);

};

#endif // AUTHENTICATE_H
