#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include "terminal.h"
#include "authenticate.h"
#include "../objects/meal.h"

Terminal::Terminal() {
    m_currentUser = 0;
    m_userList = new QQmlObjectListModel<User>();
    sessionOpen = false;
    loadFood();
    loadUser();
}

bool Terminal::isOpen() const{
    return sessionOpen;
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
            food->set_calorificValue(query.value("calorificvalue").toInt());
            food->set_classification(query.value("classification").toString());
            food->set_description(query.value("description").toString());
            food->set_image(query.value("image").toString());
            m_foodList.append(food);

        }
    }
}

void Terminal::saveUser() {
    for (int i = 0; i < m_userList->size(); i++)
        daobject.update(m_userList->get(i),"userid");
}

void Terminal::saveFood() {
    for (QList<QObject*>::iterator i = m_foodList.begin(); i != m_foodList.end(); ++i)
        daobject.update(*i,"foodid");
}

User *Terminal::at(QString username) {
    for (int i = 0; i < m_userList->size(); i++)
        if((m_userList->get(i))->property("username").toString() == username)
            return (User*)(m_userList->get(i));
    return new User();
}

bool Terminal::login(QString username, QString password) {
    Authenticate validate;
    if(!validate.loginIsValid(username,password)) return sessionOpen;
    m_currentUser = at(username);
    sessionOpen = true;
    return sessionOpen;
}

void Terminal::logout() {
    m_currentUser = new User();
    sessionOpen = false;
}

bool Terminal::selectFood(int id) {
    for (QList<QObject*>::iterator i = m_foodList.begin(); i != m_foodList.end(); ++i)
        if((*i)->property("userid").toInt() == id){
            m_selectedFood = (Food*)(*i);
            return true;
        }
    return false;
}

void Terminal::printCurrent() {
    if(isOpen()){
        qDebug() << m_currentUser->get_name()
                 << m_currentUser->get_username()
                 << m_currentUser->get_score();
    }else qDebug() << "there is no open session";
}

bool Terminal::registerMeal() {
    if(!isOpen()) return false;
    QDateTime local(QDateTime::currentDateTime());
    QString format = "t hh:mm:ss dd-MM-yyyy";
    Meal *meal = new Meal(local.toString(format), m_currentUser->get_user_id(),
                          m_selectedFood->get_food_id());
    daobject.insert(meal);
    return true;
}
