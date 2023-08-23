#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>

#include "NumericFunctions.h"

BOOST_AUTO_TEST_CASE(add_function_test)
{
    BOOST_CHECK(Logic::add(1, 2) == 3);
    BOOST_CHECK(Logic::add(5, 5) == 10);
    BOOST_CHECK(Logic::add(10, 10) == 20);
    BOOST_CHECK(Logic::add(12, 12) == 24);
}

BOOST_AUTO_TEST_CASE(sub_function_test)
{
    BOOST_CHECK(Logic::sub(1, 2) == -1);
    BOOST_CHECK(Logic::sub(5, 5) == 0);
    BOOST_CHECK(Logic::sub(10, 0) == 10);
    BOOST_CHECK(Logic::sub(12, 22) == -10);
}
