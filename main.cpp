#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QVariant>
#include <QDebug>
#include <QList>
#include "daobject.h"
#include "users.h"
#include "food.h"
#include "terminal.h"
#include "authenticate.h"

int main(int argc, char *argv[]){
    //    QGuiApplication app(argc, argv);
    //    QQmlApplicationEngine engine;
    //    QQmlContext *ctx = engine.rootContext();
    //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //    return app.exec();
    Terminal console;
    Authenticate a;
    qDebug() << a.usernameExists("lonesome013");

}
