#pragma once

#include <QObject>
#include <QList>
#include "../objects/users.h"
#include "../objects/food.h"
#include "../bd/daobject.h"
#include "assets/cpp/qqmlobjectlistmodel.h"

class Terminal : public QObject {
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(User,userList)
    QML_OBJMODEL_PROPERTY(User,topTenUsers)
    QML_OBJMODEL_PROPERTY(Food,lastMeals)
    QML_OBJMODEL_PROPERTY(Food, foodList)
    QML_WRITABLE_PROPERTY(User*, currentUser)
    QML_WRITABLE_PROPERTY(Food*, selectedFood)
    QML_WRITABLE_PROPERTY(bool,sessionOpen)
    DAObject daobject;
    static bool lessRank(const QObject *a,const QObject *b);
    User *at(QString username);
public:
    Terminal();

    Q_INVOKABLE void insertUser(QString username, QString password, QString name, QString email,
                                int age = 0, double height = 0, double weight = 0);
    Q_INVOKABLE void insertFood(QString name, QString description, int calorificvalue,
                                QString image, QString classification);

    void loadUser();
    void loadFood();
    void saveUser();
    void saveFood();
    Q_INVOKABLE void topTen();

    Q_INVOKABLE bool login(QString username, QString password);
    Q_INVOKABLE void logout();

    Q_INVOKABLE bool selectFood(int id);

    void printCurrent();

    Q_INVOKABLE bool registerMeal();

    void loadLastMeals();
};

