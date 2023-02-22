#include <QtCore>
#include <QCoreApplication>
#include <QtHttpServer/QtHttpServer>
#include <QtHttpServer/QHttpServerResponder>

#include "UserList.h"

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication a(argc, argv);

    QHttpServer httpServer;
    const auto port = httpServer.listen(QHostAddress::Any, 8000);

    if (!port)
        return 0;

    qDebug() << QString("Running on http://127.0.0.1:%1/ (Press CTRL+C to quit)").arg(port);

    UserList users;

    httpServer.route("/users", [&users](const QHttpServerRequest& request) {
        if (request.method() == QHttpServerRequest::Method::Post) { // Добавляет пользователя
            qDebug() << "url - /users, Post Request";

            auto query = request.query();

            QJsonObject newUser;
            newUser["name"] = query.queryItemValue("name");
            newUser["sex"]  = query.queryItemValue("sex");
            newUser["age"]  = query.queryItemValue("age");
            users.addUser(newUser);

            QJsonObject status;
            status["status"] = "OK";
            return QHttpServerResponse(status);

        } else if (request.method() == QHttpServerRequest::Method::Get) { // Возвращает список пользователя
            qDebug() << "url - /users, Get Request";

            return QHttpServerResponse(users.getUserList());
        } else {
            QJsonObject status;
            status["status"] = "ERROR";
            return QHttpServerResponse(status);
        }
    });

    httpServer.route("/users/<arg>", [&users](int id, const QHttpServerRequest &request) {
        if (request.method() == QHttpServerRequest::Method::Get) { // Получить пользователя по id
            qDebug() << "url - /users, Get Request";

            return QHttpServerResponse(users.getUserForId(id));
        } else if (request.method() == QHttpServerRequest::Method::Delete) { // Удалить пользователя по id
            qDebug() << "url - /users, Delete Request";

            QJsonObject status;
            status["status"] = users.deleteUserForId(id) ? "OK" : "ERROR";
            return QHttpServerResponse(status);
        } else {
            QJsonObject status;
            status["status"] = "ERROR";
            return QHttpServerResponse(status);
        }
    });

    httpServer.route("/time", QHttpServerRequest::Method::Get, []([[maybe_unused]] const QHttpServerRequest& request) {
        QJsonObject status;
        status["time"] = QTime::currentTime().toString("hh:mm:ss");
        return QHttpServerResponse(status);
    });

    return a.exec();
}
