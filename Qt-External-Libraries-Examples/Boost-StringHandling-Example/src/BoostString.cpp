#include "BoostString.h"

#include <boost/algorithm/string.hpp>
#include <boost/range.hpp>
#include <boost/format.hpp>

#include <iostream>

auto BoostString::exampleBoostStringAlgorithms() -> void
{
    {
        std::string string = "string STRING";
        qDebug() << boost::algorithm::to_upper_copy(string).c_str();
        qDebug() << boost::algorithm::to_lower_copy(string).c_str();
    }

    {
        std::string string = "  string  ";
        qDebug() << boost::algorithm::trim_left_copy(string).c_str();
        boost::algorithm::trim_left_if(string, [](const char& c) -> bool {
            return c == ' ';
        });
        qDebug() << string.c_str();
        qDebug() << boost::algorithm::trim_copy(string).c_str();
    }

    {
        std::string string = "12345";
        std::string test   = "12";

        qDebug() << boost::algorithm::starts_with(string, test);
        qDebug() << boost::algorithm::contains(string, test);
        qDebug() << boost::algorithm::equals(string, test);
        qDebug() << boost::algorithm::lexicographical_compare(string, test);
    }

    {
        std::string string = "12345";
        auto iterator = boost::algorithm::find_first(string,"3");
        if (iterator) {
            // iterator.begin();
        }
    }

    {
        std::string string = "1234512345";
        auto it = boost::algorithm::find_nth(string, "2", 1);
        qDebug() << std::distance(string.begin(), it.begin());

        auto it2 = boost::algorithm::find_head(string , 5);
        qDebug() << it2;
    }

    {
        std::string string = "1234512345";
        auto it = boost::algorithm::find_token(string , [](const char& c) -> bool {
            return c == '1' || c == '2' || c == '4';
        }, boost::algorithm::token_compress_on);

        //std::cout << it << std::endl;
    }

    {
        std::string string = "1234512345";
        qDebug() << boost::algorithm::replace_first_copy(string, "123", "000").c_str();
        qDebug() << boost::algorithm::erase_first_copy(string, "123").c_str();
    }

    {
        std::string string = "1234512345";
        std::vector<std::string> vector;
        boost::algorithm::find_all(vector, string, "123");
        QDebug debug = qDebug();

        for (const auto& element : vector) {
            debug << element.c_str();
        }
    }

    {
        typedef const boost::iterator_range<std::string::const_iterator> StringRange;

        std::string string1 = "1234512345";
        std::string string2 = "4512";

        if (boost::algorithm::ifind_first(
                    StringRange(string1.begin(), string1.end()),
                    StringRange(string2.begin(), string2.end())))
            qDebug() << "Found!";
    }

    {
        boost::format format = boost::format("1 - %1% 2 - %2%.") % "first" % "second";
        qDebug() << boost::str(format).c_str(); // format.str();
    }

    {
        std::string words = "aBc";

        if (boost::algorithm::all(words, boost::algorithm::is_lower())) {
            qDebug() << "is lower";
        } else {
            qDebug() << "is not";
        }
    }
}
