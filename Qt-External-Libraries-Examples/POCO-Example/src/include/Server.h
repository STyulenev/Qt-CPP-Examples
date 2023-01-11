#pragma once

//#include <Poco/Mutex.h>
#include <QDebug>

#include <Poco/Net/HTTPServer.h>
#include <Poco/ScopedLock.h>
#include <Poco/Util/ServerApplication.h>

/*!
 * \brief The Server class
 */
class Server : public Poco::Util::ServerApplication
{
protected:
    virtual auto main(const std::vector<std::string>& args) -> int override;
};
