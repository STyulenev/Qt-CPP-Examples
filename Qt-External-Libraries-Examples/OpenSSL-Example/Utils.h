#pragma once

#include <sstream>
#include <string>
#include <map>

namespace Utils
{

std::map<std::string, std::string> doubleSplitter(const std::string& input, const char delimiter)
{
    std::map<std::string, std::string> tokens;
    std::string token;
    std::stringstream ss(input);

    while (std::getline(ss, token, delimiter))
    {
        size_t pos = token.find('=');

        if (pos != std::string::npos)
        {
            std::string key = token.substr(0, pos);
            std::string value = token.substr(pos + 1);
            tokens.insert({key, value});
        }
    }

    return tokens;
}


} // namespace Utils
