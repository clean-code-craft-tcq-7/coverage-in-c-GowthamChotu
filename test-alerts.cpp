#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
  
  REQUIRE(TypesOfLimitCooling(PASSIVE_COOLING) == coolingLimitType(0,35));
  REQUIRE(TypesOfLimitCooling(HI_ACTIVE_COOLING) == coolingLimitType(0,45));
  REQUIRE(TypesOfLimitCooling(MED_ACTIVE_COOLING) == coolingLimitType(0,40));
  
}
