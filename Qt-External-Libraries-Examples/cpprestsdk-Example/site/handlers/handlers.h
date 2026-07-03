#pragma once

#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>

namespace app::site
{
    using path_vect = std::vector<utility::string_t>;
} // namespace app::site

class Reply
{
public:
    template<typename T = web::json::value>
    void reply(web::http::http_request _message, web::http::http_headers _headers, web::http::status_code _status, const T& _body_data)
    {
        web::http::http_response response(_status);
        response.set_body(_body_data);

        _headers.add(U("Allow"), U("GET, POST, OPTIONS")); // DELETE, PUT, ...
        _headers.add(U("Access-Control-Allow-Origin"), U("*"));
        _headers.add(U("Access-Control-Allow-Methods"), U("GET, POST, OPTIONS"));
        _headers.add(U("Access-Control-Allow-Headers"), U("*"));
        response.headers() = _headers;
        _message.reply(response);
    }

};

#ifndef CREATE_WEB_HANDLER
#define CREATE_WEB_HANDLER(handler_class_name)\
class handler_class_name : public Reply\
{\
public:\
    handler_class_name() = delete;\
    handler_class_name(path_vect&& _path, web::http::http_request& _message);\
    void handle_request(web::http::http_request& _message);\
};
#endif

namespace app::site::handlers
{ 
    CREATE_WEB_HANDLER(Test)
    CREATE_WEB_HANDLER(Test_GET)
    CREATE_WEB_HANDLER(Test_POST)
} // namespace app::site::handlers
