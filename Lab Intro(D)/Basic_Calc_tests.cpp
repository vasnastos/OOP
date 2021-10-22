#define CATCH_CONFIG_MAIN
#include "Basic_Calc.hpp"
#include "catch.hpp"

TEST_CASE("Calc test 1", "Addition")
{
    Calc c(7,5);
    REQUIRE(c.addition() == 12);
}

TEST_CASE("Calc test 2", "Substraction")
{
    Calc c(7,5);
    REQUIRE(c.reduction() == 2);
}

TEST_CASE("Calc test 3", "Multiplication")
{
    Calc c(7,5);
    REQUIRE(c.multiplication() == 35);
}

TEST_CASE("Calc test 4", "Division")
{
    Calc c(7,5);
    REQUIRE(c.division() == Approx(1.4));
}

//Compilation of codes
//g++ Basic_Calc.cpp Basic_Calc_tests.cpp -o tests
//tests.exe