#include "NetworkManager.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QEventLoop>

NetworkManager::NetworkManager(QObject* parent) :
    QObject(parent)
{

    networkManager = new QNetworkAccessManager(this);
}

NetworkManager::~NetworkManager()
{

}

void NetworkManager::getTime()
{
    QNetworkRequest request(QUrl("http://127.0.0.1:8000/time"));
    QNetworkReply* reply = networkManager->get(request);
    getReply(reply);
}

void NetworkManager::getUsers()
{
    QNetworkRequest request(QUrl("http://127.0.0.1:8000/users"));
    getReply(networkManager->get(request));
}

void NetworkManager::postUsers()
{
    QUrl url("http://127.0.0.1:8000/users");

    QUrlQuery query;
    query.addQueryItem("name", "Art");
    query.addQueryItem("sex", "male");
    query.addQueryItem("age", "18");

    url.setQuery(query.toString(QUrl::FullyEncoded).toUtf8());
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    getReply(networkManager->post(request, ""));
}

QByteArray NetworkManager::getReply(QNetworkReply* reply)
{
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->isFinished()) {
        QByteArray data = reply->readAll();
        qDebug() << data << reply->request().url().toString();

        if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200)
            qDebug() << "Error: " << reply->errorString();

        return data;
    } else {
        throw ("error");
    }
}
