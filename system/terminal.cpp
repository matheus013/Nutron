#include <QDebug>
#include <QVariant>
#include "terminal.h"
#include "authenticate.h"
#include "../objects/meal.h"
#include "QQmlHelpers"
#include <QJsonObject>
#include "./AI/geneticalgorithm.h"
#include <QVector>

Terminal::Terminal() {
    QObject::connect(&web,SIGNAL(readFoodChanged(bool)),this,SLOT(loadFood(bool)));
    QObject::connect(&web,SIGNAL(readUserChanged(bool)),this,SLOT(loadUser(bool)));
    m_currentUser = 0;
    m_userList = new QQmlObjectListModel<User>();
    m_topTenUsers = new QQmlObjectListModel<User>();
    m_lastMeals = new QQmlObjectListModel<Food>();
    m_foodList = new QQmlObjectListModel<Food>();
    m_foodFilter = new QQmlObjectListModel<Food>();
    m_diet = new Diet();
    set_sessionOpen(false);
    web.loadFood();
    web.loadUser();
    topTen();

}

void Terminal::loadLastMeals() {}

bool Terminal::lessRank(const QObject *a, const QObject *b){
    return a->property("score") > b->property("score");
}

void Terminal::insertUser(QString username, QString password, QString name, QString email,
                          int age, double height, double weight) {
    User * user = new User(username,password,name,email,age,height,weight);
    m_userList->append(user);
    web.post(user->post());
    topTen();
}

void Terminal::insertFood(QString name, int calorificvalue) {
    Food * food = new Food(name,calorificvalue);
    m_foodList->append(food);
    web.post(food->post());
    filter("");
}

void Terminal::loadUser(bool isRead) {
    if(isRead){
        m_userList->clear();
        QJsonArray jArray = web.getDataUser();
        for (int i = 0; i < jArray.size(); ++i) {
            User * user = new User(jArray[i].toObject());
            m_userList->append(user);
        }
        qSort(m_userList->begin(), m_userList->end(),Terminal::lessRank);
        topTen();
        web.set_readUser(false);
    }
}

void Terminal::loadFood(bool isRead) {
    if(isRead){
        m_foodList->clear();
        QJsonArray jArray = web.getDataFood();
        for (int i = 0; i < jArray.size(); ++i) {
            Food * food = new Food(jArray[i].toObject());
            m_foodList->append(food);
        }
        web.set_readFood(false);
    }
}


void Terminal::filter(QString reference) {
    m_foodFilter->clear();
    if(reference == "")
        for (int i = 0; i < m_foodList->size(); ++i)
            m_foodFilter->append(m_foodList->at(i));
    else
        for (int i = 0; i < m_foodList->size(); ++i){
            QString var = m_foodList->at(i)->property("name").toString();
            if(var.contains(reference,Qt::CaseInsensitive))
                m_foodFilter->append(m_foodList->at(i));
        }
}

void Terminal::topTen() {
    m_topTenUsers->clear();
    int maxFor = (m_userList->size() < 10) ? m_userList->size() : 10;
    for(int i=0;i<maxFor;i++) m_topTenUsers->append(m_userList->at(i));
}

User *Terminal::at(QString username) {
    for (int i = 0; i < m_userList->size(); i++)
        if((m_userList->get(i))->property("username").toString() == username)
            return (User*)(m_userList->get(i));
    return new User();
}

bool Terminal::login(QString username, QString password) {
    Authenticate validate(m_userList);
    if(!validate.loginIsValid(username,password)) return m_sessionOpen;
    set_currentUser(at(username));
    loadLastMeals();
    set_sessionOpen(true);
    return m_sessionOpen;
}

void Terminal::logout() {
    m_currentUser = new User();
    set_sessionOpen(false);
}

void Terminal::buildDiet() {
    if(get_sessionOpen()){
        QVector<Food *> base;
        for (int i = 0; i < m_foodList->size(); ++i)
            base << m_foodList->at(i);
        GeneticAlgorithm * ag = new GeneticAlgorithm(6, 2000, base, m_currentUser);
        ag->run();
        m_diet->load(ag->get());
    } else qDebug() << "fazer login";
}

bool Terminal::selectFood(int id) {
    set_selectedFood(m_foodList->at(id - 1));
    return m_selectedFood->get_food_id() == id;
}

void Terminal::printCurrent() {
    if(get_sessionOpen()){
        qDebug() << m_currentUser->get_name()
                 << m_currentUser->get_username()
                 << m_currentUser->get_score();
    }else qDebug() << "there is no open session";
}

bool Terminal::registerMeal() {
    if(!get_sessionOpen()) return false;
    QDateTime local(QDateTime::currentDateTime());
    QString format = "t hh:mm:ss dd-MM-yyyy";
    Meal *meal = new Meal(local.toString(format), m_currentUser->get_user_id(),
                          m_selectedFood->get_food_id());
    loadLastMeals();
    return true;
}
