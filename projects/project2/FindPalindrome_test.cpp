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
}

TEST_CASE("test palvalidity", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("rac"));
	REQUIRE(b.add("ec"));
	REQUIRE(b.add("ar"));
	REQUIRE(b.number() == 7);

	//REQUIRE(!b.toVector());
}

