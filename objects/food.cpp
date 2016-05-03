#include "food.h"
#include <QDebug>
#include <QBitArray>

Food::Food(){
    setObjectName("nutron_food");
}

Food::Food(QJsonObject obj) {
    set_food_id(obj["id"].toInt());
    set_name(obj["name"].toString());
    set_calorificvalue(obj["calorific_value"].toInt());
    set_diabetes(obj["diabetes"].toBool());
    set_high_cholesterol(obj["high_cholesterol"].toBool());
    set_anemia(obj["anemia"].toBool());
    set_hypertension(obj["hypertension"].toBool());
}

Food::Food(QString name, int calorificValue){
    qDebug() << calorificValue;
    setObjectName("nutron_food");
    set_name(name);
    set_calorificvalue(calorificValue);
    set_anemia(bool(0));
    set_high_cholesterol(bool(0));
    set_hypertension(bool(0));
    set_diabetes(bool(0));
}

void Food::setDiseases(int hypertension, int diabetes, int anemia, int high_cholesterol) {
    set_anemia(bool(anemia));
    set_high_cholesterol(bool(high_cholesterol));
    set_hypertension(bool(hypertension));
    set_diabetes(bool(diabetes));
}

QString Food::post() {
    return "new_food/" + get_name() + '/' + QString::number(get_calorificvalue()) + '/' + QString::number((int)get_diabetes())
            + '/' + QString::number((int)get_hypertension()) + '/' + QString::number((int)get_high_cholesterol()) +
            '/' + QString::number((int)get_anemia()) + '/';
}

QString Food::update() {
    return "new_food/" + QString::number(get_food_id()) + '/' + get_name() + '/' + QString::number(get_calorificvalue()) + '/' + QString::number((int)get_diabetes())
            + '/' + QString::number((int)get_hypertension()) + '/' + QString::number((int)get_high_cholesterol()) +
            '/' + QString::number((int)get_anemia()) + '/';
}

QBitArray Food::info() const {
    QBitArray bit;
    bit.resize(4);
    bit.setBit(3, (bool) get_anemia());
    bit.setBit(2, (bool) get_diabetes());
    bit.setBit(1, (bool) get_high_cholesterol());
    bit.setBit(0, (bool) get_hypertension());
}
