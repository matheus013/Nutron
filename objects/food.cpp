#include "food.h"

Food::Food(){
    setObjectName("nutron_food");
}

Food::Food(QString name, QString description, QString image,
           int calorificValue, QString classification){
    setObjectName("nutron_food");
    set_name(name);
    set_calorificvalue(calorificValue);
    set_description(description);
    set_image(image);
    set_classification(classification);
}
