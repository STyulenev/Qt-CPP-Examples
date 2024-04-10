#include "HttpServer.h"

#include <exception>

#include <QtConcurrent>
#include <QtHttpServer/QtHttpServer>
#include <QtHttpServer/QHttpServerResponder>

namespace Transport {

HttpServer::HttpServer(QObject* parent) :
    QObject(parent)
{
    httpServer = new QHttpServer(this);
    const auto port = httpServer->listen(QHostAddress::Any, 8000);

    if (!port) {
        qDebug() << "error";
        throw std::runtime_error("httpServer is not working");
    } else {
        qDebug() << QString("Running on http://127.0.0.1:%1/ (Press CTRL+C to quit)").arg(port);
    }

    httpServer->route("/users", [this](const QHttpServerRequest& request) {
        return QtConcurrent::run([this, &request]() -> QHttpServerResponse {
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
    });

    httpServer->route("/users/<arg>", [this](int id, const QHttpServerRequest &request) {
        return QtConcurrent::run([this, id, &request]() -> QHttpServerResponse {
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
    });

    httpServer->route("/time", QHttpServerRequest::Method::Get, []([[maybe_unused]] const QHttpServerRequest& request) {
        qDebug() << "/time - get request";

        return QtConcurrent::run([&request]() -> QHttpServerResponse {
            QJsonObject status;
            status["time"] = QTime::currentTime().toString("hh:mm:ss");
            return QHttpServerResponse(status);
        });
    });
}

HttpServer::~HttpServer()
{

}

} // namespace Transport
