#include "web_server.h"
#include "handlers/handlers.h"

#include <thread>

namespace app::site
{

WebServer::WebServer() :
    m_WorkFlag{ false },
    m_bInitialized{ false }
{

}

WebServer::~WebServer()
{
    try
    {
        m_bInitialized = false;
    }
    catch (...)
    {

    }
}

bool WebServer::IsInitialized()
{
    return m_bInitialized;
}

bool WebServer::Initialize()
{
    try
    {
        utility::string_t address = "http://localhost:8000";

        web::uri_builder uri(address);
        uri.append_path("/");

        m_addr = uri.to_uri().to_string();

        m_listener = std::unique_ptr<http_listener>(new http_listener(uri.to_uri()));

        if (m_listener == nullptr)
        {
            throw std::runtime_error("webserver error");
        }

        m_listener->support(web::http::methods::GET, std::bind(&WebServer::handle_get, this, std::placeholders::_1));
        m_listener->support(web::http::methods::POST, std::bind(&WebServer::handle_post, this, std::placeholders::_1));
        m_listener->support(web::http::methods::OPTIONS, std::bind(&WebServer::handle_options, this, std::placeholders::_1));

        m_bInitialized = true;
    }
    catch(...)
    {
        // ...
    }

    return m_bInitialized;
}

void  WebServer::Start()
{

    if (IsInitialized())
    {
        open().wait();
        m_WorkFlag = true;
    }
    else
    {
        throw std::runtime_error("webserver error");
    }
}

void WebServer::Stop()
{
    if (IsInitialized() && m_WorkFlag)
    {
        m_WorkFlag = false;
        //нужно завершить все входящие запросы так как они выполняются асинхронно
        //при этом новые не принимаем отбиваем
        int try_ct{ 0 };

        while (m_input_queue_msgs_size > 0)
        {
            if (try_ct > 3) break;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            try_ct++;
        }
        close().wait();
    }
}

bool WebServer::ReInitialize()
{
    try
    {
        if (IsInitialized())
        {
            Stop();
        }

        if (Initialize())
        {
            Start();
            return true;
        }
        else
        {
            // ...
        }
    }
    catch (...)
    {

    }

    return false;
}

pplx::task<void> WebServer::open()
{
    if (!IsInitialized())
    {
        throw std::runtime_error("webserver error");
    }

    return m_listener->open();
}

pplx::task<void> WebServer::close()
{
    if (!IsInitialized())
    {
        throw std::runtime_error("webserver error");
    }

    return m_listener->close();
}

void WebServer::handle_get(web::http::http_request _message)
{
    m_input_queue_msgs_size++;

    try
    {
        auto paths = web::uri::split_path(web::uri::decode(_message.relative_uri().path()));

        if (!paths.empty())
        {
            if (paths.front() == U("test"))
            {
                paths.erase(paths.begin());
                handlers::Test test(std::move(paths), _message, *this);
            }
            else
            {
                throw std::runtime_error("webserver error");
            }
        }
    }
    catch (...)
    {
        web::http::http_headers response_header;
        response_header.set_content_type(U("application/json; charset=utf-8"));

        web::json::value result = web::json::value::object();
        result[U("status")] = web::json::value::string(U("error"));

        reply(_message, response_header, web::http::status_codes::InternalError, result);
    }

    m_input_queue_msgs_size--;
}

void WebServer::handle_post(web::http::http_request _message)
{
    m_input_queue_msgs_size++;

    try
    {
        auto paths = web::uri::split_path(web::uri::decode(_message.relative_uri().path()));

        if (!paths.empty())
        {
            if (paths.front() == U("test"))
            {
                paths.erase(paths.begin());
                handlers::Test test(std::move(paths), _message, *this);
            }
            else
            {
                throw std::runtime_error("webserver error");
            }
        }
    }
    catch (...)
    {
        web::http::http_headers response_header;
        response_header.set_content_type(U("application/json; charset=utf-8"));

        web::json::value result = web::json::value::object();
        result[U("status")] = web::json::value::string(U("error"));

        reply(_message, response_header, web::http::status_codes::InternalError, result);
    }

    m_input_queue_msgs_size--;
}

void WebServer::handle_options(web::http::http_request _message)
{
    web::http::http_response resp(web::http::status_codes::OK);

    resp.headers().add(U("Allow"), U("GET, POST, OPTIONS"));
    resp.headers().add(U("Access-Control-Allow-Origin"), U("*"));
    resp.headers().add(U("Access-Control-Allow-Methods"), U("GET, POST, OPTIONS"));
    resp.headers().add(U("Access-Control-Allow-Headers"), U("*"));
    // ...

    _message.reply(resp);
}

} // namespace app::site
