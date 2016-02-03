#include <QDebug>
#include "users.h"

Users::Users(){
    setObjectName("nutron_users");
}

Users::Users(const QObject *object) {
    setObjectName("nutron_user");
    set_level(object->property("level").toInt());
    set_score(object->property("score").toInt());
    set_username(object->property("username").toString());
    set_password(object->property("password").toString());
    set_age(object->property("age").toInt());
    set_email(object->property("email").toString());
    set_height(object->property("height").toDouble());
    set_weight(object->property("weight").toDouble());
    set_name(object->property("name").toString());
}

Users::Users(QString username, QString password, QString name, QString email,
             int age, double height, double weight){
    setObjectName("nutron_user");
    set_level(0);
    set_score(0);
    set_username(username);
    set_password(password);
    set_age(age);
    set_email(email);
    set_height(height);
    set_weight(weight);
    set_name(name);
}

bool Users::isEmpty() {
    return get_id() == 0;
}

