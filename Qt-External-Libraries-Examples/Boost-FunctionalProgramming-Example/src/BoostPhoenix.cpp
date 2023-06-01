#include "BoostPhoenix.h"

#include <boost/container/vector.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <stdexcept>

#include <boost/phoenix/phoenix.hpp>
#include <boost/phoenix/statement.hpp>
#include <boost/phoenix/statement/throw.hpp>
#include <boost/phoenix/statement/try_catch.hpp>

#include <boost/phoenix/object.hpp>

struct is_odd_struct
{
    typedef bool result_type;

    template <typename T>
    auto operator()(T t) const -> bool {
        return t % 2 == 1;
    }
};
boost::phoenix::function<is_odd_struct> is_odd_phoenix;

auto is_odd(int i) -> bool
{
    return i % 2 == 1;
}

// Преобразование обычной функции в феникс функцию, тогда она не может использоваться как обычная
//BOOST_PHOENIX_ADAPT_FUNCTION(bool, is_odd, is_odd_function, 1)

auto BoostPhoenix::exampleBoostPhoenix() -> void
{
    boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

    { // Внешняя Функция
        qDebug() << std::count_if(vector.begin(), vector.end(), is_odd);
    }

    { // Лямбда функция
        auto lambda = [](int i) -> bool {
            return i % 2 == 1;
        };

        // Лямбда функция
        qDebug() << std::count_if(vector.begin(), vector.end(), lambda);
    }

    { // Феникс функция
        auto phoenix = boost::phoenix::placeholders::arg1 % 2 == 1;
        qDebug() << std::count_if(vector.begin(), vector.end(), phoenix);

        // или короткая запись
        //qDebug() << std::count_if(vector.begin(), vector.end(),
        //                          boost::phoenix::placeholders::arg1 % 2 == 1);
    }

    { // Феникс функция как структура
        qDebug() << std::count_if(vector.begin(), vector.end(), is_odd_phoenix(boost::phoenix::placeholders::arg1));
    }

    { // Использование автономной функции как феникс функцию через биндинг
        qDebug() << std::count_if(vector.begin(), vector.end(), boost::phoenix::bind(is_odd, boost::phoenix::placeholders::arg1));
    }
}

auto BoostPhoenix::exampleBoostPhoenixLazyStatements() -> void
{
    { // if_ / .else_
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        std::for_each(vector.begin(), vector.end(),
                if_(boost::phoenix::placeholders::arg1 % 2 == 1)
                [
                      boost::phoenix::placeholders::arg1 *= 2
                ]
                .else_
                [
                boost::phoenix::placeholders::arg1 *= 3
                ]);

        QDebug debug = qDebug();
        for(const auto& element : vector) {
            debug << element;
        }
    }

    { // switch_ case_ default_ ref
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        int count = 0;
        //QDebug debug = qDebug();
        std::for_each(vector.begin(), vector.end(),
                      switch_(boost::phoenix::placeholders::arg1)
                      [
                              case_<1>(boost::phoenix::placeholders::arg1 += 4),
                              case_<2>(boost::phoenix::placeholders::arg1 += 3),
                              default_(++boost::phoenix::ref(count))
                      ]);
        qDebug() << count;
        QDebug debug = qDebug();
        for(const auto& element : vector) {
            debug << element;
        }
    }

    { // while_
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };
        QDebug debug = qDebug();
        std::for_each(vector.begin(), vector.end(),
                while_(boost::phoenix::placeholders::arg1--)
                [
                      boost::phoenix::ref(debug) << boost::phoenix::placeholders::arg1
                ]
        );
    }

    { // for_
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };
        QDebug debug = qDebug();

        int i;
        std::for_each(vector.begin(), vector.end(),
            (
                for_(boost::phoenix::ref(i) = 0, boost::phoenix::ref(i) < boost::phoenix::placeholders::arg1, ++boost::phoenix::ref(i))
                [
                    boost::phoenix::ref(debug) << boost::phoenix::placeholders::arg1
                ]
            )
        );
    }
}
