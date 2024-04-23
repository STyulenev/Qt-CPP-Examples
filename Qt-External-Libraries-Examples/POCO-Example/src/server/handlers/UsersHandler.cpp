#include "UsersHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/StringTokenizer.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

#include "UserList.h"

namespace {
    Models::UserList users; // user list for testing
}

namespace Handlers {

auto UsersHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& responce) -> void
{
    try {
        Poco::URI uri(request.getURI());
        const std::string method = request.getMethod();

        qDebug() << "URI:" << uri.toString().c_str() << "Method:" << method.c_str();

        if (method == Poco::Net::HTTPRequest::HTTP_GET) {
            // http://127.0.0.1:8000/users/1
            const QStringList uriList = QString::fromStdString(uri.toString()).split('/');

            if (uriList.length() == 3) { // Получить нужный элемент по id, (например - "", "users", "1" т.е. /users/1)
                bool ok;
                const int userNumber = uriList.last().toInt(&ok);

                if (ok) {
                    responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
                    responce.setContentType("application/json");
                    std::ostream& out = responce.send();

                    QJsonDocument doc(::users.getUserForId(userNumber));
                    QString strJson(doc.toJson(QJsonDocument::Compact));

                    out << strJson.toStdString().c_str();
                    out.flush();
                    return;
                } else {
                    throw Poco::URISyntaxException("Wrong URI");
                }
            } else { // Получить все, (например - "", "users" т.е. /users)
                responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
                responce.setContentType("application/json");
                std::ostream& out = responce.send();

                QJsonDocument doc(::users.getUserList());
                QString strJson(doc.toJson(QJsonDocument::Compact));

                out << strJson.toStdString().c_str();
                out.flush();
                return;
            }
        } else if (method == Poco::Net::HTTPRequest::HTTP_POST) {
            // http://127.0.0.1:8000/users?name=John&sex=male&age=19
            Poco::URI::QueryParameters queryParms = uri.getQueryParameters();

            QJsonObject newUser;

            for (auto val : queryParms) {
                if (val.first == "name")
                    newUser["name"] = QString::fromStdString(val.second);

                if (val.first == "sex")
                    newUser["sex"] = QString::fromStdString(val.second);

                if (val.first == "age")
                    newUser["age"] = QString::fromStdString(val.second);
            }

            ::users.addUser(newUser);

            responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
            responce.setContentType("application/json");
            std::ostream& out = responce.send();

            QJsonObject json;
            json["status"] = "OK";

            QJsonDocument doc(json);
            QString strJson(doc.toJson(QJsonDocument::Compact));

            out << strJson.toStdString().c_str();
            out.flush();

            return;
        } else if (method == Poco::Net::HTTPRequest::HTTP_DELETE) {
            // http://127.0.0.1:8000/users/1
            const QStringList uriList = QString::fromStdString(uri.toString()).split('/');

            if (uriList.length() == 3) { // Получить нужный элемент по id, (например - "", "users", "1" т.е. /users/1)
                bool ok;
                const int userNumber = uriList.last().toInt(&ok);

                if (ok) {
                    responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
                    responce.setContentType("application/json");
                    std::ostream& out = responce.send();

                    if (::users.deleteUserForId(userNumber)) {
                        QJsonObject json;
                        json["status"] = "OK";

                        QJsonDocument doc(json);
                        QString strJson(doc.toJson(QJsonDocument::Compact));

                        out << strJson.toStdString().c_str();
                        out.flush();
                        return;
                    } else {
                        throw Poco::URISyntaxException("Wrong URI");
                    }
                } else {
                    throw Poco::URISyntaxException("Wrong URI");
                }
            } else {
                throw Poco::URISyntaxException("Wrong URI");
            }
        } else {

        }
    } catch (Poco::URISyntaxException & exception){
        qDebug() << exception.what();
    } catch (Poco::Exception& exception) {
        qDebug() << exception.what();
    } catch (...) {
        // ...
    }

    // error
    responce.setStatus(Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND);
    responce.setContentType("application/json");
    std::ostream& out = responce.send();

    QJsonObject json;
    json["error"] = "error";

    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    out << strJson.toStdString().c_str();
    out.flush();
}

} //namespace Handlers
