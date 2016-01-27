#include <QSqlQuery>
#include <QQueue>
#include <QDebug>
#include <QSqlError>
#include <QtCore/QtAlgorithms>
#include <QSqlRecord>
#include "daobject.h"
#include "connection.h"
#include "tablemanagement.h"
#include "users.h"

QList<Users *> DAObject::getListUsers() const {
    return listUsers;
}

QList<QObject *> DAObject::getListFoods() const {
    return listFoods;
}

DAObject::DAObject(){
    connection = new Connection("data","postgres","senha","localhost","QPSQL");
    connection->startConnection();
    if(connection->getDataConnection().isOpen()) qDebug() << "Successfully connected!";
}

DAObject::DAObject(QPriorityQueue<Users *> list){
    DAObject();
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

void DAObject::loadData(QString nameTable){
    listUsers.clear();
    TableManagement sql(nameTable);
    QSqlQuery query(sql.buildSelect());
    QSqlRecord rec = query.record();

    while(query.next()){
        qDebug() << query.value(0);

    }
    //sort list users here
}
