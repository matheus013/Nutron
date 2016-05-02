#include "webmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include "./objects/food.h"
#include "./objects/users.h"


WebManager::WebManager() {
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)),
                     this, SLOT(replyFinished(QNetworkReply *)));
    set_readFood(false);
}

void WebManager::getFoods() {
    QNetworkRequest request( QUrl("http://localhost:8080/get_foods") );
    manager->get(request);
}

void WebManager::getUsers() {
    QNetworkRequest request( QUrl("http://localhost:8080/get_users") );
    manager->get(request);
}

void WebManager::post(QString url) {
    QNetworkRequest request( QUrl( QString("http://localhost:8080/" + url) ) );
    manager->get(request);
    if(url.contains("new_food/")) loadFood();
    if(url.contains("new_user/")) loadUser();
}


void WebManager::loadUser() {
    getUsers();
    qDebug() << "Reload";
}

void WebManager::loadFood() {
    getFoods();
}

QJsonArray WebManager::convert(QString str) {
    str.push_front("[");
    str.append(']');
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    return doc.array();
}

QJsonArray WebManager::getDataUser() const {
    return dataUser;
}

QJsonArray WebManager::getDataFood() const {
    return dataFood;
}

void WebManager::replyFinished(QNetworkReply * reply) {
    if(reply->error() != QNetworkReply::NoError)
        qDebug() << reply->errorString();
    else{
        QString response = reply->readAll();
        if(response.contains("{+get_")){
            response.replace("&quot;","\"");
            response.chop(1);
            if(response.contains("_food+}")){
                response.remove("{+get_food+}");
                dataFood = convert(response);
                set_readFood(true);
            } else if(response.contains("_user+}")) {
                response.remove("{+get_user+}");
                dataUser = convert(response);
                set_readUser(true);
            }
            qDebug() << "GET successfully concluded";
        } else {
            qDebug() << "POST successfully concluded";
        }
    }
}

