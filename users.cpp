#include "users.h"

Users::Users(){
    setObjectName("nutron_users");
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

