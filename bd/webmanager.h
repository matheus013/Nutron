#pragma once

#include <QObject>
#include <QUrl>
#include <QJsonArray>
#include <QNetworkReply>
#include <QQueue>
#include <./assets/cpp/qqmlobjectlistmodel.h>
#include <./assets/cpp/qqmlhelpers.h>
#include <QEventLoop>
class WebManager : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(bool,readFood)
    QML_WRITABLE_PROPERTY(bool,readUser)
public:
    WebManager();
    void getFoods();
    void getUsers();
    void post(QString url);
    void loadUser();
    void loadFood();
    QJsonArray getDataFood() const;

    QJsonArray getDataUser() const;

private:
    QJsonArray convert(QString str);
    QQmlObjectListModel<QObject> * modeList;
    QNetworkAccessManager * manager;
    QJsonArray dataFood;
    QJsonArray dataUser;
public slots:
    void replyFinished(QNetworkReply*reply);
};
