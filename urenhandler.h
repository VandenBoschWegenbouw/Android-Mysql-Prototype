#ifndef URENHANDLER_H
#define URENHANDLER_H

#include <QObject>
#include <loginhandler.h>

class UrenHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int hoursWorked READ hoursWorked WRITE setHoursWorked NOTIFY hoursWorkedChanged)

public:
    explicit UrenHandler(QObject *parent = nullptr);
    explicit UrenHandler(WorkedHoursList *lst, LoginHandler *lHandler);

    int hoursWorked() const;

    void setHoursWorked(const int& hoursWorked);

public slots:
    void fetchHours();
    void addHours();

signals:
    void hoursWorkedChanged(const int& hoursWorked);


private:
    int mHoursWorked;

    WorkedHoursList *list;
    LoginHandler *lHandler;

    qUser mUser;
};

#endif // URENHANDLER_H
