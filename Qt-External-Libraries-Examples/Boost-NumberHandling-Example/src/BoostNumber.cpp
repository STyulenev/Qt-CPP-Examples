#include "BoostNumber.h"

#include <boost/cstdint.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/random.hpp>
#include <ctime>

auto BoostNumber::exampleBoostInteger() -> void
{
    boost::int8_t i8 = 1;
    qDebug() << sizeof(i8);

#ifndef BOOST_NO_INT64_T
    boost::uint64_t ui64 = 1;
    qDebug() << sizeof(ui64);
#endif

    boost::int_least8_t il8 = 1;
    qDebug() << sizeof(il8);

    boost::uint_least32_t uil32 = 1;
    qDebug() << sizeof(uil32);

    boost::int_fast8_t if8 = 1;
    qDebug() << sizeof(if8);

    boost::uint_fast16_t uif16 = 1;
    qDebug() << sizeof(uif16);

    boost::intmax_t imax = 1;
    qDebug() << sizeof(imax);

    qDebug() << sizeof(UINT8_C(1));

#ifndef BOOST_NO_INT64_T
    qDebug() << sizeof(INT64_C(1));
#endif
}

auto BoostNumber::exampleBoostAccumulators() -> void
{
    {
        boost::accumulators::accumulator_set<int, boost::accumulators::features<boost::accumulators::tag::count>> accumulator;
        accumulator(4);
        accumulator(-6);
        accumulator(9);

        qDebug() << "count =" << boost::accumulators::count(accumulator);
    }

    {
        boost::accumulators::accumulator_set<double,
                boost::accumulators::features<boost::accumulators::tag::mean, boost::accumulators::tag::variance>> accumulator;

        accumulator(8);
        accumulator(9);
        accumulator(10);
        accumulator(11);
        accumulator(12);

        qDebug() << "mean =" << boost::accumulators::mean(accumulator);
        qDebug() << "variance =" << boost::accumulators::variance(accumulator);
    }
}

auto BoostNumber::exampleBoostMinMax() -> void
{
    {
        boost::tuples::tuple<const int&, const int&> t = boost::minmax(2, 5);

        qDebug() << "min =" << t.get<0>();
        qDebug() << "max =" << t.get<1>();
    }

    {
        std::vector<int> vector = { 2, 3, 0, 1 };

        auto minmax_pair = boost::minmax_element(vector.begin(), vector.end());

        qDebug() << "min =" << *minmax_pair.first;
        qDebug() << "max =" << *minmax_pair.second;
    }
}

auto BoostNumber::exampleBoostRandom() -> void
{
    std::time_t now = std::time(0);
    boost::random::mt19937 gen {static_cast<std::uint32_t>(now)};
    qDebug() << "boost::random::mt19937" << gen();
}
