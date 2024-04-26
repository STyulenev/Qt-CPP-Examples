#pragma once

#include "AbstractHttpClient.h"

class QNetworkAccessManager;
class QNetworkReply;

namespace Controllers {

/*!
 * \brief Пример пользовательского HttpClient с QNetworkAccessManager
 * \details Класс-пример для пользовательского HttpClient с использованием QNetworkAccessManager.
 * Для примера реализован get-метод. По аналогии можно сделать любой другой HttpClient, например, с curl,
 * libcrp, Poco и т.д.
 */
class CustomHttpClient : public AbstractHttpClient
{
public:
    explicit CustomHttpClient(QObject* parent = nullptr);
    ~CustomHttpClient();

private:
    QByteArray getReply(QNetworkReply* reply);

public slots:
    Controllers::AbstractHttpClient* get(const QString& request) override;
    Controllers::AbstractHttpClient* post(const QString& request) override;
    Controllers::AbstractHttpClient* del(const QString& request) override;
    // other types of requests ...

    Controllers::AbstractHttpClient* then(const QJSValue& callback) override;
    Controllers::AbstractHttpClient* clean(const QJSValue& callback) override;

private:
    QNetworkAccessManager* m_networkManager;

};

} // namespace Controllers
