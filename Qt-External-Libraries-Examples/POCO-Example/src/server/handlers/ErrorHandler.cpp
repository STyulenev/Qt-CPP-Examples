#include "ErrorHandler.h"

#include <QDebug>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <Poco/URI.h>

namespace Handlers {

auto ErrorHandler::handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp) -> void
{
    Poco::URI uri(req.getURI());
    std::string method = req.getMethod();

    qDebug() << "URI: " << uri.toString().c_str() << "Method: " << req.getMethod().c_str();

    //Poco::StringTokenizer tokenizer(uri.getPath(), "/", Poco::StringTokenizer::TOK_TRIM);
    //Poco::Net::HTMLForm form(req,req.stream());

    resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    resp.setContentType("application/json");
    std::ostream& out = resp.send();

    QJsonObject json;
    json["type"] = "Error";
    json["description"] = "Unknown Api";

    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    out << strJson.toStdString().c_str();
    out.flush();
}

} //namespace Handlers
