#include "site/handlers/handlers.h"

namespace app::site::handlers
{

Test_POST::Test_POST(path_vect&& _path, web::http::http_request& _message)
{
    if (!_path.empty())
    {
        throw std::runtime_error("unknown handler");
    }

    handle_request(_message);
}

void Test_POST::handle_request(web::http::http_request& _message)
{
    web::http::http_headers response_header;
    response_header.set_content_type(U("application/json; charset=utf-8"));

    web::json::value result = web::json::value::object();
    result[U("status")] = web::json::value::string(U("ok"));

    reply(_message, response_header, web::http::status_codes::OK, result);
}

} // namespace app::site::handlers
