#include "urenhandler.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

UrenHandler::UrenHandler(QObject *parent) : QObject(parent)
{

}

UrenHandler::UrenHandler(WorkedHoursList *lst, LoginHandler *lHandler)
{
    this->list = lst;
    this->lHandler = lHandler;
}

void UrenHandler::fetchHours() {

}

void UrenHandler::addHours() {

    mUser = lHandler->getUser();

    list->appendItem({"Placeholder company", "Placeholder project", mHoursWorked});

    QSqlQuery query;

    qDebug() << mHoursWorked << " - " << mUser.getId();
    query.prepare("INSERT INTO `workedhours`(`hours`, `User_idUser`) VALUES (:hours,:idUser)");
    query.bindValue(":hours", mHoursWorked);
    query.bindValue(":idUser",mUser.getId());

    if (query.exec()) {
        qDebug() << "executed successfully!";
    } else {
        qDebug() << query.lastQuery();
        qWarning() << query.lastError();
    }
}

void UrenHandler::setHoursWorked(const int &hoursWorked) {
    if (hoursWorked == mHoursWorked)
        return;
    mHoursWorked = hoursWorked;
    emit hoursWorkedChanged(mHoursWorked);
}

int UrenHandler::hoursWorked() const {
    return mHoursWorked;
}


