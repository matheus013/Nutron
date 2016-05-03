#pragma once

#include <QObject>
#include <QList>
#include "../objects/users.h"
#include "../objects/food.h"
#include "../bd/webmanager.h"
#include "../objects/diet.h"
#include "assets/cpp/qqmlobjectlistmodel.h"

class Terminal : public QObject {
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(User, userList)
    QML_OBJMODEL_PROPERTY(User, topTenUsers)
    QML_OBJMODEL_PROPERTY(Food, lastMeals)
    QML_OBJMODEL_PROPERTY(Food, foodList)
    QML_WRITABLE_PROPERTY(User* , currentUser)
    QML_WRITABLE_PROPERTY(Food* , selectedFood)
    QML_WRITABLE_PROPERTY(bool , sessionOpen)
    QML_WRITABLE_PROPERTY(Diet* , diet)
    QML_OBJMODEL_PROPERTY(Food , foodFilter)

    WebManager web;
    static bool lessRank(const QObject *a,const QObject *b);
    User *at(QString username);
public:
    Terminal();

    Q_INVOKABLE void insertUser(QString username, QString password, QString name, QString email,
                                int age = 0, double height = 0, double weight = 0);
    Q_INVOKABLE void insertFood(QString name, int calorificvalue);

    Q_INVOKABLE void filter(QString reference);

    Q_INVOKABLE void topTen();

    Q_INVOKABLE bool login(QString username, QString password);
    Q_INVOKABLE void logout();

    Q_INVOKABLE void buildDiet();

    Q_INVOKABLE bool selectFood(int id);

    void printCurrent();

    Q_INVOKABLE bool registerMeal();

    void loadLastMeals();

public slots:
    void loadFood(bool isRead);
    void loadUser(bool isRead);
};

