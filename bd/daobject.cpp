#include <QSqlQuery>
#include <QQueue>
#include <QDebug>
#include <QSqlError>
#include <QtCore/QtAlgorithms>
#include <QSqlRecord>
#include "daobject.h"
#include "connection.h"
#include "tablemanagement.h"
#include "../objects/users.h"

DAObject::DAObject(){
    connection = new Connection("data","postgres","senha","localhost","QPSQL");
    connection->startConnection();
    if(connection->getDataConnection().isOpen()) qDebug() << "Successfully connected!";
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
