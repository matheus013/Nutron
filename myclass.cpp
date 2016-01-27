#include "myclass.h"

MyClass::MyClass(){
    setObjectName("test");
}

MyClass::MyClass(QString login){
    setObjectName("x_user");
    set_login(login);
}

bool MyClass::operator <(const MyClass other) const{
    return get_score() < other.get_score();
}
