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

TEST_CASE("test palindrome validity", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> contents;
	contents.push_back("AW");
	contents.push_back("AW");
	contents.push_back("ZO0");

	REQUIRE(!b.add(contents));
}
TEST_CASE( "cut test 1", "[cutTest1]" )
{
	FindPalindrome b;
	std::vector<std::string> testVec= {"ma", "IS", "a", "nUn", "i", "as", "aM"};
	std::vector<std::string> testVec2= {"Poor", "DAn", "is", "in", "A", "DROPP"};
	REQUIRE(b.cutTest1(testVec));
	REQUIRE(!b.cutTest1(testVec2));	
} 

TEST_CASE( "cut test 2", "[cutTest2]" )
{
	FindPalindrome b;
	std::vector<std::string> testVec= {"wAs", "it", "a"};
	std::vector<std::string> testVec2= {"Rat", "i", "Saw"};
	std::vector<std::string> testVec3= {"AMY", "muSTy" , "i"};
	std::vector<std::string> testVec4= {"jujitsu", "mY", "MA"};

	REQUIRE(b.cutTest2(testVec, testVec2));
	REQUIRE(!b.cutTest2(testVec3, testVec4));	
} 
TEST_CASE( "Find Palindrome test", "[FindPalindrome]" )
{
	FindPalindrome b;
	b.add("wAs");
	b.add("it");
	b.add("a");
	b.add("rat");
	b.add("I");
	b.add("saw");
	REQUIRE(b.number() == 2);
	b.clear();
	b.add("a");
	b.add("AAA");
	b.add("aa");
	REQUIRE(b.number() == 6);
	b.add("aAaA");
	REQUIRE(b.number() == 24);
	b.clear();
	b.add("racecar");
	REQUIRE(b.number() == 1);
	b.clear();
	b.add("was");
	b.add("it");
	b.add("a");
	b.add("rbt");
	b.add("i");
	b.add("sab");
	REQUIRE(b.number() == 0);
} 
TEST_CASE( "toVector", "[toVector]" )
{
	FindPalindrome b;
	b.add("wAs");
	b.add("it");
	b.add("a");
	b.add("rat");
	b.add("I");
	b.add("saw");
	REQUIRE(b.number() == 2);
	std::vector<std::string> v1 = {"wAs", "it", "a", "rat", "I", "saw"};
	std::vector<std::string> v2 = {"saw", "it", "a", "rat", "I", "wAs"};
	std::vector<std::vector<std::string>> v3 = {v1, v2}; 
	REQUIRE(b.toVector() == v3);
}
TEST_CASE( "Find Palindrome test with vectors", "[FindPalindrome]" )
{
	FindPalindrome b;
	b.add("ciGaR");
	b.add("to");
	b.add("ss");
	std::vector<std::string> v1 = {"it", "IN", "a", "can", "iT", "is", "SO", "tRaGIC"};
	b.add(v1);
	b.clear();
	std::vector<std::string> v2 = {"a", "aa", "AaA"};
	b.add(v2);
	REQUIRE(b.number() == 6);
	b.add("aAaA");
	REQUIRE(b.number() == 24);
	b.clear();
	b.add("it");
	b.add("wAs");
	b.add("a");
	std::vector<std::string> v3= {"it"};
	REQUIRE(b.add(v3) == false);
} 
