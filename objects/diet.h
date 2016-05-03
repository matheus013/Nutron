#pragma once

#include <QObject>
#include "./assets/cpp/qqmlobjectlistmodel.h"
#include <QString>
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

};
