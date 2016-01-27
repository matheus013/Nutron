#include "users.h"

Users::Users(){
    setObjectName("Users");
}

Users::Users(QString username, QString password, QString name, QString email,
             int age, double height, double weight){
    setObjectName("user");
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

//bool Users::operator <(const Users &user) {
//    return get_score() < user.get_score();
//}
