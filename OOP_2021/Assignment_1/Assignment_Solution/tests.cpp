#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "horse.hpp"

TEST_CASE("horse racing","move_forward")
{
  horse h(1,"horse_1",55,55,87);
  REQUIRE(h.move_forward(1,50.0)==true);
  REQUIRE(h.move_forward(4,52.6)==true);
  REQUIRE(h.move_forward(10,60.34)==true);
  REQUIRE(h.move_forward(5,67.45)==false);
  REQUIRE(h.move_forward(1,67.45)==false);
  REQUIRE(h.move_forward(11,97.12)==false);
}