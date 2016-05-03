#include "authenticate.h"
#include <QDebug>
#include <QVariant>

Authenticate::Authenticate(QQmlObjectListModel<User> *model){
    this->model = model;
}

bool Authenticate::isEmailAddress(QString email) {
    if ( email.length() == 0 ) return false;
    QString strPatt = "\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b";
    QRegExp regExp(strPatt,Qt::CaseInsensitive);
    return regExp.exactMatch(email);
}

bool Authenticate::loginIsValid(QString username, QString password) {
    for (int i = 0; i < model->size(); ++i) {
        if(model->at(i)->get_username() == username &&
                model->at(i)->get_password() == password) return true;
    }
    return false;
}

bool Authenticate::usernameValid(QString username) {
    if(username.length() < 6 || username.length() > 20) return false;
    for (int i = 0; i < model->size(); ++i) {
        if(model->at(i)->get_username() == username) return false;
    }
    return true;
}

bool Authenticate::emailValid(QString email) {
    for (int i = 0; i < model->size(); ++i) {
        if(model->at(i)->get_email() == email) return false;
    }
    return true;
}
