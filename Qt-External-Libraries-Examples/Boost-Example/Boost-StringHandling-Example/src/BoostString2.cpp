#include "BoostString2.h"

#include <boost/xpressive/xpressive.hpp>
#include <boost/tokenizer.hpp>

auto BoostString2::exampleBoostXpressive() -> void
{
    {
        std::string string = "Hello Xpressive";
        const char* c_str  = "Hello Xpressive";

        boost::xpressive::sregex expr  = boost::xpressive::sregex::compile("\\w+\\s\\w+");
        boost::xpressive::cregex cexpr = boost::xpressive::cregex::compile("\\w+\\s\\w+");

        // проверка
        qDebug() << regex_match(string, expr);
        qDebug() << regex_match(c_str, cexpr);
    }

    {
        std::string string = "Hello Xpressive";
        boost::xpressive::sregex expr = +boost::xpressive::_w >> boost::xpressive::_s >> +boost::xpressive::_w;
        qDebug() << regex_match(string, expr);
    }
}

auto BoostString2::exampleBoostTokenizer() -> void
{
    {
        std::string string = "Hello Xpressive";
        boost::tokenizer<boost::char_separator<char>> tokenizer{string};

        QDebug debug = qDebug();
        for (auto iterator = tokenizer.begin(); iterator != tokenizer.end(); ++iterator)
            debug << (*iterator).c_str();
    }

    {
        std::string string = "Hello Xpressive";
        boost::char_separator<char> separator{" "}; // {" ", "+", ... };
        boost::tokenizer<boost::char_separator<char>> tokenizer{string, separator};

        QDebug debug = qDebug();
        for (const auto& iterator : tokenizer)
            debug << iterator.c_str();
    }
}
