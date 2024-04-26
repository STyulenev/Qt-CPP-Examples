#include "TimeHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/URI.h>

namespace Handlers {

auto TimeHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& responce) -> void
{
    Poco::URI uri(request.getURI());
    const std::string method = request.getMethod();

    qDebug() << "URI: " << uri.toString().c_str() << "Method: " << method.c_str();

    //Poco::StringTokenizer tokenizer(uri.getPath(), "/", Poco::StringTokenizer::TOK_TRIM);
    //Poco::Net::HTMLForm form(req,req.stream());

    if (method == Poco::Net::HTTPRequest::HTTP_GET) {
        responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        responce.setContentType("application/json");
        std::ostream& out = responce.send();

        QJsonObject json;
        json["time"] = QTime::currentTime().toString("hh:mm:ss");

        QJsonDocument doc(json);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        out << strJson.toStdString().c_str();
        out.flush();

        //return;

    } else {
        qDebug() << "?????";
    }

    { // ответ
        responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        responce.setContentType("application/json");
        std::ostream& out = responce.send();
        out << "OK" << std::endl;
        out.flush();
    }
}

} //namespace Handlers
