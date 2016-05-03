#include "util.h"
#include <QVector>
#include <QtMath>
#include <QBitArray>
#include <QDebug>

Util::Util() {}

double Util::standardDeviation(QVector<double> vector) {
    int deviation = 0, mid = average(vector);
    foreach (int aux, vector)
        deviation += qPow(aux - mid,2);
    return (double) qSqrt(deviation / (vector.size() - 1));
}

double Util::average(QVector<double> vector) {
    return sum(vector) / vector.size();
}

double Util::sum(QVector<double> vector) {
    double sum = 0;
    foreach (int aux, vector)
        sum += aux;
    return sum;
}

double Util::sum(QVector<Food *> vector){
    double sum = 0;
    foreach (Food* aux, vector)
        sum += aux->get_calorificvalue();
    return sum;
}

bool Util::approach(double number,double total , double margin) {
    return (number < total * double(1 + margin) && (number > total * double(1 - margin)));
}

QBitArray Util::join(QBitArray a, QBitArray b) {
    int start = a.size();
    a.resize(start + b.size());
    for (int i = start; i < a.size(); ++i)
        a.setBit(i,b.at(i - start));
    return a;
}
