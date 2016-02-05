#pragma once

#include <QObject>
#include "QQmlHelpers"

class Food : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int, food_id)
    QML_WRITABLE_PROPERTY(int, calorificValue)
    QML_WRITABLE_PROPERTY(QString, classification)
    QML_WRITABLE_PROPERTY(QString, description)
    QML_WRITABLE_PROPERTY(QString, image)
    QML_WRITABLE_PROPERTY(QString, name)
public:
    Food();
    Food(QString name,QString description, QString image ,int calorificValue, QString classification);
};
