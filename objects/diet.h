#pragma once

#include <QObject>
#include <QVector>
#include <QString>
#include "./assets/cpp/qqmlobjectlistmodel.h"
#include "food.h"

class Diet : public QObject {
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(Food, sunday)
    QML_OBJMODEL_PROPERTY(Food, monday)
    QML_OBJMODEL_PROPERTY(Food, tuesday)
    QML_OBJMODEL_PROPERTY(Food, wednesday)
    QML_OBJMODEL_PROPERTY(Food, thursday)
    QML_OBJMODEL_PROPERTY(Food, friday)
    QML_OBJMODEL_PROPERTY(Food, saturday)
public:
    Diet();
    Diet(QVector< QVector<Food*> > week);
    void load(QVector< QVector<Food*> > week);

};
