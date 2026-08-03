#include <catch2/catch_test_macros.hpp>

#include "NumericFunctions.h"

TEST_CASE("Test Logic::Numeric", "[test 1]")
{
    Logic::Numeric* className = new Logic::Numeric(2, 0);

    REQUIRE(className->getFirstNumber() == 2);
    REQUIRE(className->getSecondNumber() == 0);
    REQUIRE(className->add() == 2);
    REQUIRE(className->sub() == 2);
    REQUIRE(className->multi() == 0);

    delete className;
};
