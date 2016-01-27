#include "food.h"

Food::Food(){

}

Food::Food(QString name, QString description, QString image, int calorificValue){
    set_name(name);
    set_calorificValue(calorificValue);
    set_description(description);
    set_image(image);
}
