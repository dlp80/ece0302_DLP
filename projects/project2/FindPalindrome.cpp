#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
//possibly leave unchanged
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

/*this is the default constructor. therefore, we should make an empty vector
to hold all of the input words that we are checking for palindromeability*/
FindPalindrome::FindPalindrome()
{
	vector<string> checkplndr(0);
	//std::vector<std::string>* checkplndr = new std::vector<std::string>();
}

FindPalindrome::~FindPalindrome()
{

}

//counts the number of elements in the vector
int FindPalindrome::number() const
{
	int count = 0;
	for(int i = 0; i < checkplndr.size(); i++){
		count++;
	}
	return count;
}

//clears all elements from the vector
void FindPalindrome::clear()
{
	for(int i = 0; i < checkplndr.size(); i++){
		if (checkplndr.size() == 0){
			break;
		}
		else{
		  checkplndr.pop_back();
		}
	}
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

//add a word to the vector. return false if failed true if succeed
bool FindPalindrome::add(const string & value)
{
	bool valid, vvalid;
	//checking if the value is valid in the first place
	for(int i = 0; i < value.length(); i++){
 		if ((value[i] < 'A' && value[i] > 'Z') || (value[i] < 'a' && value[i] > 'z')){
		 vvalid = false;
		}
		vvalid = true;
	}
	
	//checking if it exists in vector already
	if (vvalid == true){
	for(int i = 0; i < checkplndr.size(); i++){
		if(convertToLowerCase(value) != convertToLowerCase(checkplndr[i])){
			checkplndr.push_back(value);
			valid = true;
		}
		else{
			valid = false;
			break;
			}
		}
	}
	return valid;
}

//add a vector. return false if failed and true if succeed
bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

/*if we make an instance of this class then we can add words
to the instance and the instance will determine all possible orders of the words
that will form sentence palindromes

now note: a word does not need to be an exact word. each word will be a string
consisting of solely alphabet characters and no punctuation.

capitalization is preserved, but must be discarded when determining if a sentence is a palindrome
>>must use some kind of temp? 
capitalization does not make for unique words

discrete part: if we have N unique words, then there exists N! possible orderings (sentences)
>> we must implement the factorial recusively
>>NOT EVERY COMBO WILL BE A PALINDROME

>>make cut conditions. #1 check that no more than 1 character appears an odd number of times
>>else cut
>>these cut functions should be functional as priv vars */