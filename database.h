#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <qsqldatabase.h>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

signals:

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");



};

#endif // DATABASE_H
