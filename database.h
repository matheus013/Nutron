#pragma once

#include <QObject>
#include "QQmlHelpers"

class DatabaseManagement : public QObject {
    Q_OBJECT
public:
    DatabaseManagement();
    void createTable();
    void createDB();
    void dropTable();
};
