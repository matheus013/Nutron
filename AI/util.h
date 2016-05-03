#pragma once
#include <QObject>
#include "objects/food.h"

class Util : public QObject {
    Q_OBJECT
public:
    Util();
    double standardDeviation(QVector<double> vector);
    double average(QVector<double> vector);
    double sum(QVector<double> vector);
    double sum(QVector<Food*> vector);
    bool approach(double number, double total, double margin);
    static QBitArray join(QBitArray a,QBitArray b);
};
