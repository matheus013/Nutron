#pragma once

#include <QObject>
#include <QList>
#include "users.h"
#include "food.h"
#include "daobject.h"

class Terminal {
    QList<QObject*> userList;
    QList<QObject*> foodList;
    DAObject daobject;
public:
    Terminal();
    void loadUser();
    void loadFood();
    void saveUser();
    void saveFood();

};

