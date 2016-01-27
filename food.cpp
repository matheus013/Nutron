#include "food.h"

Food::Food(){
    setObjectName("food");
}

Food::Food(QString name, QString description, QString image,
           int calorificValue, QString classification){
    setObjectName("food");
    set_name(name);
    set_calorificValue(calorificValue);
    set_description(description);
    set_image(image);
    set_classification(classification);
}
