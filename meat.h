#pragma once
#include <QObject>
#include <QQmlHelpers>

class Meat : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(QString,name)
    QML_WRITABLE_PROPERTY(QString,description)
    QML_WRITABLE_PROPERTY(QList<QObject*>,foods)
    QML_WRITABLE_PROPERTY(QString,classification)
public:
    Meat();
    Meat(QString name, QString description, QByteArray foods, QString classification);
    QString toInsert();
    QString toUpdate();
    QString convertToString();
    void convertFromString(QByteArray str);
};
