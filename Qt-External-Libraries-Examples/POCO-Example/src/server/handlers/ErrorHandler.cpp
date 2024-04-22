#include "ErrorHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/URI.h>

namespace Handlers {

auto ErrorHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& responce) -> void
{
    Poco::URI uri(request.getURI());
    const std::string method = request.getMethod();

    qDebug() << "URI: " << uri.toString().c_str() << "Method: " << method.c_str();

    //Poco::StringTokenizer tokenizer(uri.getPath(), "/", Poco::StringTokenizer::TOK_TRIM);
    //Poco::Net::HTMLForm form(req,req.stream());

    responce.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    responce.setContentType("application/json");
    std::ostream& out = responce.send();

    QJsonObject json;
    json["type"] = "Error";
    json["description"] = "Unknown Api";

    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    out << strJson.toStdString().c_str();
    out.flush();
}

} //namespace Handlers
