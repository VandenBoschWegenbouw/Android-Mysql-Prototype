#include "database.h"

#include <QDebug>

Database::Database(QObject *parent) : QObject(parent)
{
    db.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=qtprototype;");
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()) {
        qWarning() << "Could not connect to the database";
    } else {
        qDebug() << "Successfully connected to the database";
    }
}
