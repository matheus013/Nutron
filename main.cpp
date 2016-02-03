#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QDebug>
#include <QList>
#include "system/terminal.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    Terminal console;
    ctx->setContextProperty("_console",&console);
    engine.load(QUrl(QStringLiteral("qrc:/gui/main.qml")));
    return app.exec();
}

