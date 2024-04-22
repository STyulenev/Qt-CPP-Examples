#include "TimeHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/URI.h>

namespace Handlers {

auto TimeHandler::handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp) -> void
{
    Poco::URI uri(req.getURI());
    std::string method = req.getMethod();

    qDebug() << "URI: " << uri.toString().c_str() << "Method: " << req.getMethod().c_str();

    //Poco::StringTokenizer tokenizer(uri.getPath(), "/", Poco::StringTokenizer::TOK_TRIM);
    //Poco::Net::HTMLForm form(req,req.stream());

    if (!method.compare("GET")) {
        resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        resp.setContentType("application/json");
        std::ostream& out = resp.send();

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
        resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        resp.setContentType("application/json");
        std::ostream& out = resp.send();
        out << "OK" << std::endl;
        out.flush();
    }
}

} //namespace Handlers
