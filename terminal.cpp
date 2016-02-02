#include "terminal.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>

Terminal::Terminal() {
}


void Terminal::loadUser() {
    QSqlQuery query;
    query.prepare( "SELECT * FROM nutron_user" );
    if(!query.exec()) {
        qDebug() << query.lastError();
    }
    else{
        while(query.next()) {
            Users * user = new Users();
            user->set_username(query.value("username").toString());
            user->set_age(query.value("age").toInt());
            user->set_email(query.value("email").toString());
            user->set_height(query.value("height").toDouble());
            user->set_id(query.value("id").toInt());
            user->set_level(query.value("level").toInt());
            user->set_name(query.value("name").toString());
            user->set_password(query.value("password").toString());
            user->set_score(query.value("score").toInt());
            user->set_weight(query.value("weight").toDouble());
            userList.append(user);
        }
    }
}

void Terminal::loadFood() {
    QSqlQuery query;
    query.prepare( "SELECT * FROM nutron_food" );
    if(!query.exec()) {
        qDebug() << query.lastError();
    }
    else{
        while(query.next()) {
            Food* food = new Food();
            food->set_id(query.value("id").toInt());
            food->set_name(query.value("name").toString());
            food->set_calorificValue(query.value("calorificvalue").toInt());
            food->set_classification(query.value("classification").toString());
            food->set_description(query.value("description").toString());
            food->set_image(query.value("image").toString());
            userList.append(food);
        }
    }
}

void Terminal::saveUser() {
    for (QList<QObject*>::iterator i = userList.begin(); i != userList.end(); ++i)
        daobject.update(*i);
}

void Terminal::saveFood() {
    for (QList<QObject*>::iterator i = foodList.begin(); i != foodList.end(); ++i)
        daobject.update(*i);
}

