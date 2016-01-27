#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QVariant>
#include <QDebug>
#include <QList>
#include "daobject.h"
#include "users.h"
#include "food.h"


int main(int argc, char *argv[]){
    //    QGuiApplication app(argc, argv);
    //    QQmlApplicationEngine engine;
    //    QQmlContext *ctx = engine.rootContext();
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    return app.exec();
    DAObject dao;

//    dao.insert(new Food("frango","gostoso","",1000,"SS"));
//    Users * master = new Users("mod","123456","Administrador",".9.",0,0,0);
//    dao.insert(master);
    dao.loadData("user");
    qDebug() << dao.getListUsers().count();
}
