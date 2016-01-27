#include <QSqlQuery>
#include <QQueue>
#include <QDebug>
#include <QSqlError>
#include "daobject.h"
#include "connection.h"
#include "tablemanagement.h"
#include "users.h"

QPriorityQueue<Users *> DAObject::getDataUsers() const {
    return rankUsers;
}

QList<QObject *> DAObject::getListUsers() const
{
    return listUsers;
}

QList<QObject *> DAObject::getListFoods() const
{
    return listFoods;
}

DAObject::DAObject(){
    connection = new Connection("data","postgres","senha","localhost","QPSQL");
    connection->startConnection();
    if(connection->getDataConnection().isOpen()) qDebug() << "Successfully connected!";
}

DAObject::DAObject(QPriorityQueue<Users *> list){
    DAObject();
    rankUsers = list;
}

void DAObject::insert(QObject *object){
    TableManagement sql(object);
    QSqlQuery query;
    QString textQuery = sql.buildInsert();

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::update(QObject *object,QString where){
    TableManagement sql(object);
    QSqlQuery query;
    QString textQuery = sql.buildUpdate(where);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QString where){
    TableManagement sql(object);
    QSqlQuery query;
    QString textQuery = sql.buildDetele(where);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QStringList where, QString myOperator){
    TableManagement sql(object);
    QSqlQuery query;
    QString textQuery = sql.buildDetele(where, myOperator);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::removeAll(QObject *object){
    TableManagement sql(object);
    QSqlQuery query;
    QString textQuery = sql.buildDeleteAll();

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::customCommand(QString textQuery){
    QSqlQuery query;

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::loadData(QObject* object, QString nameTable){
    if(nameTable == "")
        nameTable = object->objectName();
    rankUsers.clear();
    listUsers.clear();
    TableManagement sql(nameTable);
    QSqlQuery query;
    query.prepare(sql.buildSelect());
    while(query.next()){
        Users *user = new Users();
        user->set_age(query.value("age").toInt());
        user->set_email(query.value("email").toString());
        user->set_height(query.value("height").toDouble());
        user->set_id(query.value("id").toInt());
        user->set_level(query.value("level").toInt());
        user->set_name(query.value("name").toString());
        user->set_password(query.value("password").toString());
        user->set_score(query.value("score").toInt());
        user->set_username(query.value("username").toString());
        user->set_weight(query.value("weight").toDouble());
        rankUsers.push(user);
        listUsers.append(user);
    }
}
