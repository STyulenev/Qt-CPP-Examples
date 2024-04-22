#include "UsersHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/StringTokenizer.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

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

            if (uriList.length() == 3) { // for example - "", "users", "1"
                bool ok;
                const int userNumber = uriList.last().toInt(&ok);

                if (ok) {
                    responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
                    responce.setContentType("application/json");
                    std::ostream& out = responce.send();

                    QJsonObject json;
                    json["name"] = "Adam";
                    json["sex"]  = "male";
                    json["age"]  = 22;

                    QJsonDocument doc(json);
                    QString strJson(doc.toJson(QJsonDocument::Compact));

                    out << strJson.toStdString().c_str();
                    out.flush();
                    return;
                } else {
                    throw Poco::URISyntaxException("Wrong URI");
                }
            } else {
                throw Poco::URISyntaxException("Unknown URI");
            }
        } else if (method == Poco::Net::HTTPRequest::HTTP_POST) {
            // http://127.0.0.1:8000/users?name=John&sex=man&age=19
            Poco::URI::QueryParameters queryParms = uri.getQueryParameters();

            for (auto val : queryParms) {
                qDebug() << QString::fromStdString(val.first) << QString::fromStdString(val.second);
            }

            responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
            responce.setContentType("application/json");
            std::ostream& out = responce.send();

            QJsonObject json;
            json["users"] = "get users";

            QJsonDocument doc(json);
            QString strJson(doc.toJson(QJsonDocument::Compact));

            out << strJson.toStdString().c_str();
            out.flush();

            return;
        } else if (method == Poco::Net::HTTPRequest::HTTP_DELETE) {
            // delete
        } else {

        }
    } catch (Poco::URISyntaxException & exception){
        qDebug() << exception.what();
    } catch (Poco::Exception& exception) {

    } catch (...) {

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
