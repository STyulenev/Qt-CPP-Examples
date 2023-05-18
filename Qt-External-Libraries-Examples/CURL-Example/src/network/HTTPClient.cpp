#include "HTTPClient.h"

#include <curl/curl.h>
#include <curl/urlapi.h>

#include <QDebug>

HTTPClient* HTTPClient::self = 0;

auto getUrlResponse(char* buffer, size_t size, size_t count, std::string* response) -> size_t;

auto getUrlResponse(char* buffer, size_t size, size_t count, std::string* response) -> size_t
{
    size_t recv_size = size * count;

    response->clear();
    response->append(buffer);

    return recv_size;
}

HTTPClient::HTTPClient()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

HTTPClient::~HTTPClient()
{
    curl_global_cleanup();
}

HTTPClient* HTTPClient::getClient()
{
    if (!self) {
        self = new HTTPClient();
    }

    return self;
}

auto HTTPClient::getServerCurrentTime() -> QString
{
    std::string response;
    CURL* handle;

    handle = curl_easy_init();

    curl_easy_setopt(handle, CURLOPT_URL, "http://127.0.0.1:8000/time");
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &getUrlResponse);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(handle);
    curl_easy_cleanup(handle);

    return response.c_str();
}

auto HTTPClient::getServerUserList() -> void
{
    std::string response;
    CURL* handle;

    handle = curl_easy_init();

    curl_easy_setopt(handle, CURLOPT_URL, "http://127.0.0.1:8000/users");
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &getUrlResponse);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(handle);
    curl_easy_cleanup(handle);

    //QString str = response.c_str();

    //qDebug() << response.c_str();

    //return response.c_str();
    QString string = response.c_str();
    QJsonDocument doc1 = QJsonDocument::fromJson(string.toUtf8());
    if (!doc1.isObject()) {
        // handle parse error...
    }

    QJsonArray array = doc1.array();

    for (int i = 0; i < array.size(); i++) {
        qDebug() << array.at(i).toObject()["name"].toString() << array.at(i).toObject()["sex"].toString() << array.at(i).toObject()["age"].toString();
    }
}

auto HTTPClient::postServerSendNewUser() -> void
{
    std::string response;
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        const char* data = "data to send";

        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/users?name=John&sex=man&age=19");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &getUrlResponse);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_POST, 1);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            qDebug() << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        } else {
            qDebug() << response.c_str();
        }

        curl_easy_cleanup(curl);
    }
}
