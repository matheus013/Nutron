#include "authenticate.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>

Authenticate::Authenticate(){}

bool Authenticate::isEmailAddress(QString email) {
    if ( email.length() == 0 ) return false;
    QString strPatt = "\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b";
    QRegExp regExp(strPatt,Qt::CaseInsensitive);
    return regExp.exactMatch(email);
}

bool Authenticate::loginIsValid(QString username, QString password) {
    QSqlQuery query;
    query.prepare( "SELECT * FROM nutron_user" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        while(query.next())
            if(query.value("username").toString() == username){
                if(query.value("password").toString() == password) return true;
                else return false;
            }
    return false;
}

bool Authenticate::usernameExists(QString username) {
    if(username.length() <= 6 || username.length() >= 20) return false;
    QSqlQuery query;
    query.prepare( "SELECT * FROM nutron_user" );
    if(!query.exec())
        qDebug() << query.lastError();
    else
        while(query.next())
            if(query.value("username").toString() == username)
                return false;
    return true;
}
