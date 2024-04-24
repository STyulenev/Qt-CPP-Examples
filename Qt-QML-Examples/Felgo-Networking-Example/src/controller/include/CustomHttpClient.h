#pragma once

#include <QObject>
#include <QJSValue>

namespace Controllers {

class CustomHttpClient : public QObject
{
    Q_OBJECT

public:
    explicit CustomHttpClient(QObject* parent = nullptr);
    ~CustomHttpClient();

public slots:
    CustomHttpClient* get(const QString& request);
    CustomHttpClient* post(const QString& request);
    CustomHttpClient* del(const QString& request);
    // other types of requests ...

    CustomHttpClient* then(QJSValue callback);
    CustomHttpClient* clean(QJSValue callback);

private:
    QString m_request;
    QString m_result;

};

} // namespace Controllers
