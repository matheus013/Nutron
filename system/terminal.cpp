#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include "terminal.h"
#include "authenticate.h"
#include "../objects/meal.h"
#include "QQmlHelpers"

Terminal::Terminal() {
    m_currentUser = 0;
    m_userList = new QQmlObjectListModel<User>();
    m_topTenUsers = new QQmlObjectListModel<User>();
    m_lastMeals = new QQmlObjectListModel<Food>();
    m_foodList = new QQmlObjectListModel<Food>();
    set_sessionOpen(false);
    loadFood();
    loadUser();
    topTen();
}

void Terminal::loadLastMeals() {
    QSqlQuery query;
    m_lastMeals->clear();
    QString tag = "SELECT * FROM historic_meals WHERE author = '" +
            QString::number(get_currentUser()->get_user_id()) + '\'';
    query.prepare(tag);
    if(!query.exec())
        qDebug() << query.lastError();
    else{
        while(query.next()) {
            Food* food = (Food*) m_foodList->at(query.value("food").toInt() - 1);
            m_lastMeals->append(food);
        }
    }
    qDebug() << m_lastMeals->size();
}

bool Terminal::lessRank(const QObject *a, const QObject *b){
    return a->property("score") > b->property("score");
}

void Terminal::insertUser(QString username, QString password, QString name, QString email,
                          int age, double height, double weight) {
    User * user = new User(username,password,name,email,age,height,weight);
    daobject.insert(user);
    loadUser();
}

void Terminal::insertFood(QString name, QString description, int calorificvalue,
                          QString image, QString classification) {
    Food * food = new Food(name,description,image,calorificvalue,classification);
    daobject.insert(food);
    loadFood();
}

void Terminal::loadUser() {
    QSqlQuery query;
    m_userList->clear();
    query.prepare( "SELECT * FROM nutron_user" );
    if(!query.exec()) {
        qDebug() << query.lastError();
    }
    else{
        while(query.next()) {
            User * user = new User();
            user->set_username(query.value("username").toString());
            user->set_age(query.value("age").toInt());
            user->set_email(query.value("email").toString());
            user->set_height(query.value("height").toDouble());
            user->set_user_id(query.value("user_id").toInt());
            user->set_level(query.value("level").toInt());
            user->set_name(query.value("name").toString());
            user->set_password(query.value("password").toString());
            user->set_score(query.value("score").toInt());
            user->set_weight(query.value("weight").toDouble());
            m_userList->append(user);
        }
    }
    qSort(m_userList->begin(),m_userList->end(),Terminal::lessRank);
    topTen();
}

void Terminal::loadFood() {
    QSqlQuery query;
    query.clear();
    query.prepare( "SELECT * FROM nutron_food" );
    if(!query.exec()) {
        qDebug() << query.lastError();
    }
    else{
        while(query.next()) {
            Food* food = new Food();
            food->set_food_id(query.value("food_id").toInt());
            food->set_name(query.value("name").toString());
            food->set_calorificvalue(query.value("calorificvalue").toInt());
            food->set_classification(query.value("classification").toString());
            food->set_description(query.value("description").toString());
            food->set_image(query.value("image").toString());
            m_foodList->append(food);
        }
    }
}

void Terminal::saveUser() {
    for (int i = 0; i < m_userList->size(); i++)
        daobject.update(m_userList->get(i),"userid");
}

void Terminal::saveFood() {
    for (QQmlObjectListModel<Food>::iterator i = m_foodList->begin(); i != m_foodList->end(); ++i)
        daobject.update(*i,"foodid");
}

void Terminal::topTen() {
    m_topTenUsers->clear();
    int maxFor = (m_userList->size() < 10) ? m_userList->size() : 10;
    for(int i=0;i<maxFor;i++) m_topTenUsers->append(m_userList->at(i));
    qDebug() << m_topTenUsers->size();
}

User *Terminal::at(QString username) {
    for (int i = 0; i < m_userList->size(); i++)
        if((m_userList->get(i))->property("username").toString() == username)
            return (User*)(m_userList->get(i));
    return new User();
}

bool Terminal::login(QString username, QString password) {
    Authenticate validate;
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
    daobject.insert(meal);
    loadLastMeals();
    return true;
}
