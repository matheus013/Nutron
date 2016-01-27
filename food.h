#pragma once
#include <QObject>
#include <QQmlHelpers>

class Food : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(QString,name)
    QML_WRITABLE_PROPERTY(QString,description)
    QML_WRITABLE_PROPERTY(int,calorificValue)
    QML_WRITABLE_PROPERTY(QString, image)
public:
    Food();
    Food(QString name,QString description, QString image ,int calorificValue);
    QString toInsert();
    QString toUpdate();
};
