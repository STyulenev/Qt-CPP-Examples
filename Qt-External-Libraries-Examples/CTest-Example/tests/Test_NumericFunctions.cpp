#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"

#include "NumericFunctions.h"

TEST_CASE("Test add_function", "[unit-test]")
{
    REQUIRE(Logic::add(1, 2) == 3);
    REQUIRE(Logic::add(5, 5) == 10);
    REQUIRE(Logic::add(10, 10) == 20);
    REQUIRE(Logic::add(12, 12) == 24);
}

TEST_CASE("Test sub_function", "[unit-test]")
{
    REQUIRE(Logic::sub(1, 2) == -1);
    REQUIRE(Logic::sub(5, 5) == 0);
    REQUIRE(Logic::sub(10, 0) == 10);
    REQUIRE(Logic::sub(12, 22) == -10);
}
