#include "site/handlers/handlers.h"

namespace app::site::handlers
{

Test::Test(path_vect&& _path, web::http::http_request& _message)
{
    if (_message.method() == web::http::methods::GET)
    {
        handlers::Test_GET test(std::move(_path), _message);
    }
    else if (_message.method() == web::http::methods::POST)
    {
        handlers::Test_POST test(std::move(_path), _message);
    }

    handle_request(_message);
}

void Test::handle_request(web::http::http_request& _message)
{
    throw std::runtime_error("webserver error");
}

} // namespace app::site::handlers
