#include "geneticalgorithm.h"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm() {}

GeneticAlgorithm::GeneticAlgorithm(int mealPerDay, int calories,  QVector<Food *> base, const User *user) {
    m_base = base;
    m_populationSize = mealPerDay*7;
    m_mealPerDay = mealPerDay;
    m_calories = calories;
    m_user.resize(4);

    m_user.setBit(0, bool(user->get_anemia()));
    m_user.setBit(1, bool(user->get_diabetes()));
    m_user.setBit(2, bool(user->get_high_cholesterol()));
    m_user.setBit(3, bool(user->get_hypertension()));

    srand(time(NULL));

}

void GeneticAlgorithm::run() {
    buildPopulation();
    do {
        cross();
        mutation();
    } while (rating());
}

void GeneticAlgorithm::print() {
    foreach (Data i, m_population) {
        QString out = "";
        foreach (Food* f, i) {
            out += '[' + f->get_name() + " " + QString::number(f->get_calorificvalue()) + ']';
        }
        qDebug() << out;
    }
}

Week GeneticAlgorithm::get() {
    return m_population;
}

void GeneticAlgorithm::cross() {
    for (int i = 0; i < m_population.size(); ++i) {
        QVector<Food *> gene = makeGene(m_mealPerDay);
        if(adaptation(m_population[i]) < adaptation(gene)) {
            m_population[i] = gene;
        }
    }
}

void GeneticAlgorithm::buildPopulation() {
    while(m_population.size() != 7){
        m_population << makeGene(m_mealPerDay);
    }
}

void GeneticAlgorithm::mutation() {
    for (int i = 0; i < m_population.size(); ++i) {
        QVector<Food *> gene = makeGene(m_mealPerDay);
        if(adaptation(m_population[i]) < adaptation(gene))
            m_population[i] = gene;
    }
}

int GeneticAlgorithm::adaptation(Data gene) {
    int adaptationScore = 0;
    foreach (Food * current, gene)
        adaptationScore += score(current);
    return adaptationScore;
}

int GeneticAlgorithm::score(Food *reference) {
    double first = (double) harmony(Util::join(m_user,reference->info()));
    double secund = (double) reference->get_calorificvalue();
    return  ((first/8) * 0.6 - (secund/1100) * 0.4) * 1000;
}

int GeneticAlgorithm::harmony(QBitArray reference, int i) {
    if(i == reference.size()/ 2 - 1)
        return (reference[i] == reference[reference.size() - 1 - i]);
    return (reference[i] == reference[reference.size() - 1 - i]) +  harmony(reference, ++i);
}

bool GeneticAlgorithm::rating() {
    QVector<double> scores;
    foreach (QVector<Food *> gene, m_population)
        scores << adaptation(gene);
    double rate = util.standardDeviation(scores);
    return rate < -50 || rate > 50;
}

Data GeneticAlgorithm::makeGene(int size) {
    Data gene;
    while(gene.size() != size) {
        int i = rand() % m_base.size();
        gene << m_base.at(i);
    }
    return gene;
}
