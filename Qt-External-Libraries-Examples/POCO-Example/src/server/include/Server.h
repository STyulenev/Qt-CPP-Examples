#pragma once

#include "Poco/Util/ServerApplication.h"

/*!
 * \brief The Server class
 */
class Server : public Poco::Util::ServerApplication
{
protected:
    virtual auto main(const std::vector<std::string>& args) -> int override;
};
