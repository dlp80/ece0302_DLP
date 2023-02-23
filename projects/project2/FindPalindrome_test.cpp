#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
	//REQUIRE(b.clear());
	//REQUIRE(b.number() == 0);
}

TEST_CASE("test palvalidity", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("ta"));
	REQUIRE(b.add("CO"));
	REQUIRE(b.add("cat"));
	REQUIRE(b.number() == 1);
	//REQUIRE(b.add("ce"));
	//REQUIRE(b.add("car"));
	//REQUIRE(b.add("ra"));

}

