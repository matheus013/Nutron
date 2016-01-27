#include "meat.h"
#include <QJsonArray>
#include <QJsonDocument>
#include "food.h"
#include "daofood.h"

Meat::Meat(){}

Meat::Meat(QString name, QString description, QByteArray foods, QString classification){
    set_name(name);
    set_description(description);
    set_classification(classification);
    convertFromString(foods);
}

QString Meat::toInsert(){
    return "INSERT INTO meat (name, description, foods, classification) VALUES('"
            + get_name() + "', '" + get_description() +  "' , '" + convertToString() +
            "' , '" + get_classification() + "')";
}

QString Meat::toUpdate(){
    return "UPDATE food SET name = '" + get_name() + "', description = '" + get_description() +
            "', classification = '" + get_classification() + "', foods = '" + convertToString() +
            "'' WHERE id = " + get_id();
}


QString Meat::convertToString(){
    QJsonArray array;
    QJsonDocument data;
    for (QList<QObject*>::iterator i = m_foods.begin();i != m_foods.end(); ++i)
        array.append(((Food*)(*i))->get_id());
    data.setArray(array);
    return data.toJson();
}

void Meat::convertFromString(QByteArray str){
    QJsonDocument doc = QJsonDocument::fromJson(str);
    QJsonArray array = doc.array();
    DAOFood dataFood;
    for (int var = 0; var < array.size(); ++var)
        m_foods.append(dataFood.at(array.at(var).toInt()));
}
