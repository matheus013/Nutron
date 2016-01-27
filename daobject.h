#pragma once

#include <queue>
#include <QObject>
#include <QList>
#include "connection.h"
#include "QPriorityQueue"
#include "users.h"


class DAObject : QObject{
    Q_OBJECT
    QPriorityQueue<Users*> rankUsers;
    QList<QObject*> listUsers;
    QList<QObject*> listFoods;
    Connection *connection;
public:
    DAObject();
    DAObject(QPriorityQueue<Users *> list);
    void insert(QObject *object);
    void update(QObject *object, QString where);
    void remove(QObject *object, QString where);
    void remove(QObject *object, QStringList where, QString myOperator);
    void removeAll(QObject *object);
    void customCommand(QString textQuery);
    void loadData(QObject *object, QString nameTable = "");
    QPriorityQueue<Users *> getDataUsers() const;
    QList<QObject *> getListUsers() const;
    QList<QObject *> getListFoods() const;
};
