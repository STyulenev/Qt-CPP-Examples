#include "BoostNumber.h"

#include <boost/cstdint.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

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
