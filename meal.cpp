#include "meal.h"

Meal::Meal(){

}

Meal::Meal(QString instant, int author, int food) {
    set_author(author);
    set_food(food);
    set_instant(instant);
}
