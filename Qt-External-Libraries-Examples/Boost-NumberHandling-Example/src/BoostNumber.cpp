#include "BoostNumber.h"

#include <boost/cstdint.hpp>

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
