#ifndef QUSER_H
#define QUSER_H

#include <QString>

class qUser
{
public:
    qUser();
    qUser(int id, QString name, QString password);

    QString getPassword() const;

    QString getName() const;

    int getId() const;

private:
    int id;
    QString name;
    QString password;


};

#endif // QUSER_H
