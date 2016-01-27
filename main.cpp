#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QVariant>
#include "daobject.h"
#include "users.h"

int main(int argc, char *argv[]){
    //    QGuiApplication app(argc, argv);
    //    QQmlApplicationEngine engine;
    //    QQmlContext *ctx = engine.rootContext();
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    return app.exec();
    DAObject dao;

    dao.insert(new Users("lonesome","matheus23","Matheus I.","matheus.bs@ic.ufal.br",
                         20,1.8,116));
}
