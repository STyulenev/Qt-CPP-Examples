#include "HTTPClient.h"

#include <curl/curl.h>
#include <curl/urlapi.h>

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
