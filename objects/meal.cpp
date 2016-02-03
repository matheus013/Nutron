#include "meal.h"

Meal::Meal(){
    setObjectName("historic_meals");
}

Meal::Meal(QString instant, int author, int food) {
    setObjectName("historic_meals");
    set_author(author);
    set_food(food);
    set_instant(instant);
}
