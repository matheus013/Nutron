#include <QDebug>
#include "users.h"
#include <QJsonObject>
#include <QJsonDocument>

User::User(){
    setObjectName("nutron_user");
}

User::User(const QObject *object) {
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
    set_photo(object->property("photo").toString());
}

User::User(QJsonObject obj) {
    set_username(obj["username"].toString());
    set_password(obj["password"].toString());
    set_email(obj["email"].toString());
    set_photo(obj["photo"].toString());
    set_name(obj["name"].toString());
    set_age(obj["age"].toInt());
    set_level(obj["level"].toInt());
    set_score(obj["score"].toInt());
    set_height(obj["height"].toInt());
    set_weight(obj["weight"].toInt());
    set_diabetes(obj["diabetes"].toBool());
    set_high_cholesterol(obj["high_cholesterol"].toBool());
    set_anemia(obj["anemia"].toBool());
    set_hypertension(obj["hypertension"].toBool());

}

User::User(QString username, QString password, QString name, QString email,
             int age, int height, int weight){
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
    set_photo("https://image.freepik.com/icones-gratis/usuario-masculino-imagem-no-perfil_318-37825.jpg");
    set_diabetes(0);
    set_high_cholesterol(0);
    set_anemia(0);
    set_hypertension(0);
}


QString User::post() {

}

