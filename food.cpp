#include "food.h"

Food::Food(){

}

Food::Food(QString name, QString description, QString image, int calorificValue){
    set_name(name);
    set_calorificValue(calorificValue);
    set_description(description);
    set_image(image);
}

QString Food::toInsert(){
    return "INSERT INTO food (name, calorificValue, description, image) VALUES('" +
            get_name() + "','" + get_description() + "'," + QString::number(get_calorificValue()) + ", '" +
            get_image() + ")";
}

QString Food::toUpdate(){
    return "UPDATE food SET name = '" + get_name() + "', description = '" + get_description() +
            "', calorificValue = " + get_calorificValue() + ", image = '" + get_image() + "' WHERE id = " + get_id();
}

