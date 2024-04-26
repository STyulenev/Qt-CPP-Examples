#pragma once

#include <QObject>
#include <QJSValue>

namespace Controllers {

class AbstractHttpClient : public QObject
{
    Q_OBJECT

public:
    explicit AbstractHttpClient(QObject* parent = nullptr) : QObject(parent) { };
    virtual ~AbstractHttpClient() = default;

public slots:
    virtual Controllers::AbstractHttpClient* get(const QString& request) = 0;
    virtual Controllers::AbstractHttpClient* post(const QString& request) = 0;
    virtual Controllers::AbstractHttpClient* del(const QString& request) = 0;
    // other types of requests ...

    virtual Controllers::AbstractHttpClient* then(const QJSValue& callback) = 0;
    virtual Controllers::AbstractHttpClient* clean(const QJSValue& callback) = 0;

protected:
    QString m_request;
    QString m_result;

};

} // namespace Controllers
