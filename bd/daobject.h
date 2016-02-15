#pragma once

#include <queue>
#include <QObject>
#include <QList>
#include "connection.h"
#include "../objects/users.h"


class DAObject : QObject{
    Q_OBJECT
//    QPriorityQueue<Users*> rankUsers;
    Connection *connection;
public:
    DAObject();
    void insert(QObject *object);
    void update(QObject *object, QString where = "id");
    void remove(QObject *object, QString where = "id");
    void remove(QObject *object, QStringList where, QString myOperator);
    void removeAll(QObject *object);
    void customCommand(QString textQuery);
};
