#include "HTTPClient.h"

#include <cpr/cpr.h>

#include <QDebug>
#include <QThread>

namespace Network {

HTTPClient::HTTPClient(QObject* parent) :
    AbstractHTTPClient(parent)
{

}

HTTPClient::~HTTPClient()
{

}

auto HTTPClient::getServerCurrentTime() -> void
{
    qDebug() << "Worker" << QThread::currentThreadId();

    cpr::Response response = cpr::Get(cpr::Url{"http://127.0.0.1:8000/time"},
                               cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                               cpr::Parameters{{"anon", "true"}, {"key", "value"}});

    if (response.status_code == 200) {
        qDebug() << response.header["content-type"]; // application/json; charset=utf-8
        qDebug() << response.text;                   // JSON text string

        emit serverUserList(QString(response.text.c_str()));
    } else {
        emit error(QString("%1 : %2").arg(response.status_code).arg(response.header["content-type"].c_str()));
    }
}

auto HTTPClient::getServerUserList() -> void
{
    qDebug() << "Worker" << QThread::currentThreadId();

    cpr::Response response = cpr::Get(cpr::Url{"http://127.0.0.1:8000/users"},
                                      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});

    if (response.status_code == 200) {
        qDebug() << response.header["content-type"];
        qDebug() << response.text;

        emit serverUserList(QString(response.text.c_str()));
    } else {
        emit error(QString("%1 : %2").arg(response.status_code).arg(response.header["content-type"].c_str()));
    }
}

auto HTTPClient::postServerSendNewUser() -> void
{

    qDebug() << "Worker" << QThread::currentThreadId();

    cpr::Response response = cpr::Post(cpr::Url{"http://127.0.0.1:8000/users?name=John&sex=man&age=19"},
                                       cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                                       cpr::Parameters{{"anon", "true"}, {"key", "value"}});

    if (response.status_code == 200) {
        qDebug() << response.header["content-type"];
        qDebug() << response.text;

        emit serverUserList(QString(response.text.c_str()));
    } else {
        emit error(QString("%1 : %2").arg(response.status_code).arg(response.header["content-type"].c_str()));
    }
}

auto HTTPClient::deleteServerFirstUser() -> void
{
    qDebug() << "Worker" << QThread::currentThreadId();

    cpr::Response response = cpr::Delete(cpr::Url{"http://127.0.0.1:8000/users/0"},
                                       cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                                       cpr::Parameters{{"anon", "true"}, {"key", "value"}});

    if (response.status_code == 200) {
        qDebug() << response.header["content-type"];
        qDebug() << response.text;

        emit serverUserList(QString(response.text.c_str()));
    } else {
        emit error(QString("%1 : %2").arg(response.status_code).arg(response.header["content-type"].c_str()));
    }
}

} // namespace Network
