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
