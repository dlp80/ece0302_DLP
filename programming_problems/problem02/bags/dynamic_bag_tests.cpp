#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0); //checked
  b.remove(0); //checked
  b.isEmpty(); //checked
  b.getCurrentSize(); //checked
  b.clear(); //checked
  b.getFrequencyOf(0);
  b.contains(0);
}

//tests if current size is correctly returned
TEST_CASE("first case", "[Dynamic Bag]"){
  DynamicBag<int> b;
  b.add(13);
  b.add(12);
  b.add(10000);
  b.add(4);
  b.add(100);
  b.add(33);

  REQUIRE(b.getCurrentSize() == 6);
}

TEST_CASE("second case", "[Dynamic Bag]"){
DynamicBag<int> b;

  b.add(1);
  b.add(438);
  b.add(0);
  b.add(12121);

  b.remove(438);

  REQUIRE_FALSE(b.contains(438));
  REQUIRE_FALSE(b.isEmpty());
}


TEST_CASE("third case", "[Dynamic Bag]"){
DynamicBag<int> b;

  b.add(13);
  b.add(12);

  REQUIRE_FALSE(b.isEmpty());
}

TEST_CASE("fourth case", "[Dynamic Bag]"){
DynamicBag<int> b;

  b.add(13);
  b.add(12);

  REQUIRE_FALSE(b.contains(12));
}

TEST_CASE("fifth case", "[Dynamic Bag]"){
DynamicBag<int> b;

  b.add(1);
  b.add(438);
  b.add(0);
  b.add(12121);

  b.clear();

  REQUIRE(b.isEmpty());
}

TEST_CASE("sixth case", "[Dynamic Bag]"){
DynamicBag<int> b;

  b.add(1);
  b.add(438);
  b.add(0);
  b.add(12121);
  b.add(10);
  b.add(12121);
  b.add(3);
  b.add(12121);
  b.add(55);
  

  b.remove(12121);
  b.getFrequencyOf(12121);

  REQUIRE(b.getFrequencyOf(12121) == 0);
}