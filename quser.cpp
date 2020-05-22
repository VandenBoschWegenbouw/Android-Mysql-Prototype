#include "quser.h"

qUser::qUser()
{

}

qUser::qUser(int id, QString name, QString password)
{
    this->id = id;
    this->name = name;
    this->password = password;
}

QString qUser::getPassword() const
{
    return password;
}

QString qUser::getName() const
{
    return name;
}

int qUser::getId() const
{
    return id;
}
