#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QDebug>
#include <QList>
#include "terminal.h"

int main(int argc, char *argv[]){
    //    QGuiApplication app(argc, argv);
    //    QQmlApplicationEngine engine;
    //    QQmlContext *ctx = engine.rootContext();
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    return app.exec();
    Terminal console;
//    console.printCurrent();
    console.login("lonesome","matheus23");
//    console.logout();
    qDebug() << console.isOpen();

}


