#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <loginhandler.h>
#include <urenhandler.h>
#include <workedhourslist.h>
#include <workedhoursmodel.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<WorkedHoursModel>("WorkedHours", 1, 0, "WorkedHoursModel");
    qmlRegisterUncreatableType<WorkedHoursList>("WorkedHours", 1, 0, "WorkedHoursList",
        QStringLiteral("ToDoList should not be created in QML"));

    WorkedHoursList toDoList;
    LoginHandler lHandler(&toDoList);
    UrenHandler uHandler(&toDoList, &lHandler);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("loginHandler", &lHandler);
    engine.rootContext()->setContextProperty("urenHandler", &uHandler);
    engine.rootContext()->setContextProperty(QStringLiteral("workedHoursList"), &toDoList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);



    engine.load(url);


    return app.exec();
}
