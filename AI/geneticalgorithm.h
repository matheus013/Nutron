#pragma once

#include <QObject>
#include <QBitArray>
#include <QVector>
#include "objects/users.h"
#include "objects/food.h"
#include "assets/cpp/qqmlobjectlistmodel.h"
#include "util.h"

typedef QVector<Food*> Data;
typedef QVector< QVector<Food*> > Week;

class GeneticAlgorithm : public QObject {
    Q_OBJECT
    Data m_base;
    Week m_population;
    QBitArray m_user;
    int m_populationSize;
    int m_calories;
    int m_mealPerDay;
    Util util;
public:
    GeneticAlgorithm();
    GeneticAlgorithm(int mealPerDay, int calories, QVector<Food *> base, const User * user);
    void run();
    void print();
    Week get();
private:
    void cross();
    void buildPopulation();
    void mutation();
    int adaptation(Data gene);
    int score(Food *reference);
    int harmony(QBitArray reference, int i = 0);
    bool rating();

    Data makeGene(int size);

};
