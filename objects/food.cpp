#include "food.h"
#include <QDebug>

Food::Food(){
    setObjectName("nutron_food");
}

Food::Food(QJsonObject obj) {
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
