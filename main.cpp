#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QDebug>
#include <QList>
#include "system/terminal.h"
#include "system/authenticate.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    Terminal console;
    Authenticate validate;
    ctx->setContextProperty("_console",&console);
    ctx->setContextProperty("_authenticate",&validate);
    engine.load(QUrl(QStringLiteral("qrc:/gui/main.qml")));
    return app.exec();
}

