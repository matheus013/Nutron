#include "person.h"
#include <QStringList>
#include <QDebug>

Person::Person(){}

Person::Person(QString name, int age, double height, double weight, int score){
    set_name(name);
    set_age(age);
    set_height(height);
    set_weight(weight);
    set_score(score);
//    qDebug() << toInsert();
}

QString Person::toInsert(){
    return "INSERT INTO `mydata`.`person` (`id`, `name`, `age`, `score`, `height`, `weight`)"
           "VALUES ('" + get_name() + "', '" + QString::number(get_age()) +
            "', '" + QString::number(get_score()) + "', '" + QString::number(get_height()) +
            "', '" + QString::number(get_weight()) + "')";
}
QString Person::toUpdate(){
    return "UPDATE person SET name = '" + get_name() + "' ,age = " + QString::number(get_age()) +
           ",height = " + QString::number(get_height()) + ",weight = " + QString::number(get_weight()) +
           " ,score = " + QString::number(get_score()) + " WHERE id = " + QString::number(get_id());
}

