#pragma once

#include <atomic>
#include <stdexcept>

#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>

#include "handlers/handlers.h"

namespace app::site
{

using namespace web::http::experimental::listener;


class WebServer final : public Reply
{
public:

    WebServer();
    ~WebServer();

    bool isInitialized();
    bool initialize();
    bool reInitialize();

    void start();
    void stop();

private:
    pplx::task<void> open();
    pplx::task<void> close();
    
    void handle_get(web::http::http_request _message);
    void handle_post(web::http::http_request _message);
    void handle_options(web::http::http_request _message);

private:
    std::atomic_bool               m_WorkFlag{ false };
    bool                           m_bInitialized{ false };
    utility::string_t              m_addr{};
    std::unique_ptr<http_listener> m_listener;
    std::atomic_uint64_t           m_input_queue_msgs_size{ 0 };

};

} // namespace app::site
