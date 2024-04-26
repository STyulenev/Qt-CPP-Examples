#include "CustomHttpClient.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QEventLoop>

namespace Controllers {

CustomHttpClient::CustomHttpClient(QObject* parent) :
    AbstractHttpClient(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
}

CustomHttpClient::~CustomHttpClient()
{

}

QByteArray CustomHttpClient::getReply(QNetworkReply* reply)
{
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->isFinished()) {
        QByteArray data = reply->readAll();
        m_result = data;

        if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200)
            m_result = QString("Error: %1").arg(reply->errorString());

        return data;
    } else {
        throw ("error");
    }
}

AbstractHttpClient* CustomHttpClient::get(const QString& request)
{
    // some http get-request process ...

    // for example, QNetworkAccessManager
    QNetworkRequest networkRequest(request);
    QNetworkReply* reply = m_networkManager->get(networkRequest);
    getReply(reply);

    return this;
}

AbstractHttpClient* CustomHttpClient::post(const QString& request)
{
    // some http post-request process ...

    m_result = "{ status: \"OK\" }";
    m_request = request;

    return this;
}

AbstractHttpClient* CustomHttpClient::del(const QString& request)
{
    // some http post-request process ...

    m_result = "{ status: \"OK\" }";
    m_request = request;

    return this;
}

AbstractHttpClient* CustomHttpClient::then(const QJSValue& callback)
{
    QJSValueList list;
    list.append(m_request);
    list.append(m_result);

    callback.call(list);

    return this;
}

AbstractHttpClient* CustomHttpClient::clean(const QJSValue& callback)
{
    m_result.clear();
    m_request.clear();

    callback.call();

    return this;
}

} // namespace Controllers
