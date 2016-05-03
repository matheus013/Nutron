#include "diet.h"

Diet::Diet() {
    m_saturday = new QQmlObjectListModel<Food>();
    m_sunday = new QQmlObjectListModel<Food>();
    m_thursday = new QQmlObjectListModel<Food>();
    m_tuesday = new QQmlObjectListModel<Food>();
    m_friday = new QQmlObjectListModel<Food>();
    m_wednesday = new QQmlObjectListModel<Food>();
    m_monday = new QQmlObjectListModel<Food>();

}

Diet::Diet(QVector<QVector<Food *> > week) {
    m_saturday = new QQmlObjectListModel<Food>();
    m_sunday = new QQmlObjectListModel<Food>();
    m_thursday = new QQmlObjectListModel<Food>();
    m_tuesday = new QQmlObjectListModel<Food>();
    m_friday = new QQmlObjectListModel<Food>();
    m_wednesday = new QQmlObjectListModel<Food>();
    m_monday = new QQmlObjectListModel<Food>();
    load(week);
}

void Diet::load(QVector<QVector<Food *> > week) {
    m_sunday->clear();
    m_monday->clear();
    m_tuesday->clear();
    m_wednesday->clear();
    m_thursday->clear();
    m_friday->clear();
    m_saturday->clear();
    foreach (Food * var, week[0])
        m_sunday->append(var);
    foreach (Food * var, week[1])
        m_monday->append(var);
    foreach (Food * var, week[2])
        m_tuesday->append(var);
    foreach (Food * var, week[3])
        m_wednesday->append(var);
    foreach (Food * var, week[4])
        m_thursday->append(var);
    foreach (Food * var, week[5])
        m_friday->append(var);
    foreach (Food * var, week[6])
        m_saturday->append(var);

}
