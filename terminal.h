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
    Users *currentUser;
    Food * selectedFood;
    bool sessionOpen;

    static bool lessRank(const QObject *a,const QObject *b);
    Users *at(QString username);
public:
    Terminal();
    void insertUser(QString username, QString password, QString name, int age, double height,
                    double weight, QString email);
    void insertFood(QString name, QString description, int calorificvalue, QString image,
                    QString classification);

    void loadUser();
    void loadFood();
    void saveUser();
    void saveFood();

    bool login(QString username, QString password);
    void logout();

    bool selectFood(int id);

    void printCurrent();

    bool registerMeal();

    bool isOpen() const;
};

