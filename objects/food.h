#pragma once

#include <QObject>
#include "QQmlHelpers"
#include <QJsonObject>

class Food : public QObject {
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int, food_id)
    QML_WRITABLE_PROPERTY(int, calorificvalue)
    QML_WRITABLE_PROPERTY(QString, name)

    QML_WRITABLE_PROPERTY(bool, hypertension)
    QML_WRITABLE_PROPERTY(bool, diabetes)
    QML_WRITABLE_PROPERTY(bool, anemia)
    QML_WRITABLE_PROPERTY(bool, high_cholesterol)
public:
    Food();
    Food(QJsonObject obj);
    Food(QString name, int calorificValue);
    void setDiseases(int hypertension,int diabetes,int anemia, int high_cholesterol);
    QString post();
    QString update();
    QBitArray info() const;
};
