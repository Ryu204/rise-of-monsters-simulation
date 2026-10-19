#include "rise_of_monsters_simulation/adder.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace roms;

TEST_CASE("add function adds two integers") {
  SECTION("adding positive numbers") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(10, 20) == 30);
  }
}
