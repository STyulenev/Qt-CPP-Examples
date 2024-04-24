#include "CustomHttpClient.h"

//#include <QDebug>

namespace Controllers {

CustomHttpClient::CustomHttpClient(QObject* parent) :
    QObject(parent)
{

}

CustomHttpClient::~CustomHttpClient()
{

}

CustomHttpClient* CustomHttpClient::get(const QString& request)
{
    // some http get-request process ...

    m_result = "{ status: \"OK\" }";
    m_request = request;

    return this;
}

CustomHttpClient* CustomHttpClient::post(const QString& request)
{
    // some http post-request process ...

    m_result = "{ status: \"OK\" }";
    m_request = request;

    return this;
}

CustomHttpClient* CustomHttpClient::del(const QString& request)
{
    // some http post-request process ...

    m_result = "{ status: \"OK\" }";
    m_request = request;

    return this;
}

CustomHttpClient* CustomHttpClient::then(QJSValue callback)
{
    QJSValueList list;
    list.append(m_request);
    list.append(m_result);

    callback.call(list);

    return this;
}

CustomHttpClient* CustomHttpClient::clean(QJSValue callback)
{
    m_result.clear();
    m_request.clear();

    callback.call();

    return this;
}

} // namespace Controllers
