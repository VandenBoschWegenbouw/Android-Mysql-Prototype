#include "loginhandler.h"
#include <qdebug.h>
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkRequest>
#include <qnetworkreply.h>
#include <qfile.h>

LoginHandler::LoginHandler(QObject *parent) : QObject(parent)
{

}

LoginHandler::LoginHandler(WorkedHoursList *lst) : list(nullptr)
{
    list = lst;
    //connect(&manager, &QNetworkAccessManager::finished, this, &LoginHandler::onManagerFinished);
}

void LoginHandler::setUsername(const QString &username) {
    if (username == mUsername)
        return;
    mUsername = username;
    emit usernameChanged(mUsername);
}

void LoginHandler::setPassword(const QString &password) {

    QString pWord = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Keccak_256).toHex());
    qDebug() << pWord;
    if (pWord == mPassword)
        return;
    mPassword = pWord;
    emit passwordChanged(mPassword);
}

QString LoginHandler::username() const {
    return mUsername;
}

QString LoginHandler::password() const {
    return mPassword;
}

void LoginHandler::login() {
    QNetworkRequest request(QUrl("http://localhost:9000/users/login"));
    request.setRawHeader("Content-Type", "application/json");
    QFile file("C:\\Users\\joris\\Desktop\\login.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray arr = file.readAll();
        qDebug() << arr.toHex();

        connect(&manager, &QNetworkAccessManager::finished, this, &LoginHandler::onManagerFinished);

        QNetworkReply *reply = manager.post(request,arr);






    }

//    QNetworkRequest request(QUrl("http://localhost:9000/users/test/1"));
//    request.setRawHeader("Content-Type", "application/json");

//    //connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(slotProgress(qint64,qint64)));
//    //connect(reply, SIGNAL(readyRead()), SLOT(replyReadyRead()));

//    connect(&manager, &QNetworkAccessManager::finished, this, &LoginHandler::onManagerFinished);



//    //connect(&manager, SIGNAL(QNetworkReply::Finished()), this, SLOT(onManagerFinished(QNetworkReply *)));

//    manager.get(request);

    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE name = :name AND password = :pass");
    query.bindValue(":name", mUsername);
    query.bindValue(":pass", mPassword);
    if (query.exec()) {
        if(query.numRowsAffected() == 1) {
            query.next();
            if(mUsername == query.value("name") && mPassword == query.value("password")){
                qDebug() << "Switch screens and you are logged in";

                user = qUser(query.value("idUser").toInt(), query.value("name").toString(), query.value("password").toString());

                QSqlQuery q;
                q.prepare("SELECT * FROM workedhours WHERE User_idUser = :userId");
                q.bindValue(":userId", query.value("idUser"));

                if (q.exec()) {
                    while(q.next()){
                        list->appendItem({"Placeholder company", "Placeholder project", q.value("hours").toInt()});
                    }
                }

                emit logUserIn();


            }
        }
    } else {
        qWarning() << "Was unable to execute query";
        qWarning() << query.lastError();
    }
}

qUser LoginHandler::getUser() const
{
    return user;
}

void LoginHandler::onManagerFinished(QNetworkReply *reply) {
    qDebug() << "Reply: " << reply->readAll();
}

void LoginHandler::slotProgress(qint64 received, qint64 total) {
    qDebug() << "Total: " << total << " Received: " << received;
    if (total > 0 && received > 0) {
        int percentage = (100/total)*received;
        qDebug() << "Progress: " << percentage << "% received";
    }
}

void LoginHandler::replyReadyRead() {
    qDebug() << "ready";

    qDebug() << reply->error();

    qDebug() << reply->readAll();
}
