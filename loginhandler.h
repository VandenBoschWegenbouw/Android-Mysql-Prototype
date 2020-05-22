#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QObject>
#include <database.h>
#include <QQmlApplicationEngine>
#include "workedhourslist.h"
#include "quser.h"
#include <QNetworkAccessManager>

class LoginHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)



public:
    explicit LoginHandler(QObject *parent = nullptr);
    explicit LoginHandler(WorkedHoursList *lst);

    QString username() const;
    QString password() const;

    void setUsername(const QString &username);
    void setPassword(const QString &password);

    qUser getUser() const;

    void onManagerFinished(QNetworkReply *reply);

public slots:
    void login();
    void slotProgress(qint64, qint64);
    void replyReadyRead();

signals:
    void usernameChanged(const QString& username);
    void passwordChanged(const QString& password);
    void logUserIn();

private:
    QString mUsername;
    QString mPassword;

    Database db;

    WorkedHoursList *list;

    qUser user;

    QNetworkAccessManager manager;
    QNetworkReply *reply = 0;

};

#endif // LOGINHANDLER_H
