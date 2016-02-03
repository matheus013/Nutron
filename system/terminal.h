#pragma once

#include <QObject>
#include <QList>
#include "../objects/users.h"
#include "../objects/food.h"
#include "../bd/daobject.h"

class Terminal : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(QList<QObject*>, userList)
    QML_WRITABLE_PROPERTY(QList<QObject*>, foodList)
    QML_WRITABLE_PROPERTY(Users*, currentUser)
    QML_WRITABLE_PROPERTY(Food*, selectedFood)
    DAObject daobject;
    bool sessionOpen;

    static bool lessRank(const QObject *a,const QObject *b);
    Users *at(QString username);
public:
    Terminal();

    Q_INVOKABLE void insertUser(QString username, QString password, QString name, int age, double height,
                    double weight, QString email);
    Q_INVOKABLE void insertFood(QString name, QString description, int calorificvalue, QString image,
                    QString classification);

    void loadUser();
    void loadFood();
    void saveUser();
    void saveFood();

    Q_INVOKABLE bool login(QString username, QString password);
    Q_INVOKABLE void logout();

    Q_INVOKABLE bool selectFood(int id);

    void printCurrent();

    Q_INVOKABLE bool registerMeal();

    Q_INVOKABLE bool isOpen() const;
};

