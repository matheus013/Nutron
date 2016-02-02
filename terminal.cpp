#include "terminal.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>

bool Terminal::lessRank(const QObject *a, const QObject *b){
    return a->property("score") > b->property("score");
}

Terminal::Terminal() {
}

void Terminal::insertUser(QString username, QString password, QString name,
                          int age, double height, double weight, QString email) {
    Users * user = new Users(username,password,name,email,age,height,weight);
    daobject.insert(user);
    loadUser();
}

void Terminal::insertFood(QString name, QString description, int calorificvalue,
                          QString image, QString classification) {
    Food * food = new Food(name,description,image,calorificvalue,classification);
    daobject.insert(food);
    loadFood();

}


void Terminal::loadUser() {
    QSqlQuery query;
    userList.clear();
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
    qSort(userList.begin(),userList.end(),Terminal::lessRank);
}

void Terminal::loadFood() {
    QSqlQuery query;
    query.clear();
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
            foodList.append(food);
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

void Terminal::printUser() {
    for (QList<QObject*>::iterator i = userList.begin(); i != userList.end(); ++i)
        qDebug() << (*i)->property("name").toString()
                 << (*i)->property("score").toInt();
}

void Terminal::printFood() {
    for (QList<QObject*>::iterator i = foodList.begin(); i != foodList.end(); ++i)
        qDebug() << (*i)->property("name").toString()
                 << (*i)->property("calorificvalue").toInt();
}

