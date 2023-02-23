#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value) //see static void ; this permanent change - will need to put everything in a temp first
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//self made helper function?

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector){ //one for the call one for the base case
    
    //one for the call one for the base case
    if (currentStringVector.size() == candidateStringVector.size()) {
        // Check if the current combination is a palindrome
        string currentString;
        for (const auto& str : currentStringVector) {
            currentString += str;
        }
        if (isPalindrome(currentString))
		{
			if (currentString.size() >= candidateStringVector.size()) {
			numpal++;
            palcount.push_back(currentString);
        }}
        // Print the current combination
        for (const auto& str : currentStringVector) {
            cout << str << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < candidateStringVector.size(); i++) {
            bool found = false;
            for (int j = 0; j < currentStringVector.size(); j++) {
                if (candidateStringVector[i] == currentStringVector[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                currentStringVector.push_back(candidateStringVector[i]);
                recursiveFindPalindromes(candidateStringVector, currentStringVector);
                currentStringVector.pop_back();
            }
        }
    }

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
	//initialize numpal
	numpal = 0;
	//vector to store strings in after add
	plndr = vector<string>();
	//vector to store completed palindromes in
	palcount = vector<string>();
	//empty vector
	emptyvec = vector<string>();

}

FindPalindrome::~FindPalindrome()
{
	clear();
	numpal = 0;
}

//Returns the current number of sentence palindromes in the
//FindPalindrome instance.
int FindPalindrome::number() const
{
    return numpal;
}

//clears all elements from the vector
void FindPalindrome::clear()
{
	palcount.clear();
	plndr.clear();
	numpal = 0;
}


bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	    string temp;
    int len = stringVector.size();
    int cnt = 0, oddcount = 0; // initialize variables

    // Concatenate the vector contents into a temporary string
    for (int i = 0; i < len; i++) {
        temp += stringVector[i];
    }

    int len2 = temp.size();

    // Determine if even length or odd length
    if (len2 % 2 == 0) { // Even choice
        // If even length
        for (int j = 0; j < len2; j++) {
            for (int i = j + 1; i < len2; i++) { // Increment i, not j
                if (temp[j] == temp[i]) {
                    cnt++;
                }
            }
            if (cnt % 2 == 1) {
                return false;
            }
            cnt = 0; // Reset counter for next iteration
        }
    }
    else if (len2 % 2 == 1) { // Odd choice
        for (int j = 0; j < len2; j++) {
            for (int i = j + 1; i < len2; i++) { // Increment i, not j
                if (temp[j] == temp[i]) {
                    cnt++;
                }
            }
            if (cnt % 2 == 1) {
                oddcount++;
            }
            cnt = 0; // Reset counter for next iteration
        }
        if (oddcount > 1) {
            return false;
        }
    }
    return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	vector<string>test1 = stringVector1;
	vector<string>test2 = stringVector1;
	string t1, t2, firsthalf, secondhalf;
	int size1 = test1.size(), size2 = test2.size();

	for(int i =0; i < size1; i++){
		convertToLowerCase(test1[i]);
		t1 += test1[i]; 
	}

	for(int i =0; i < size1; i++){
		convertToLowerCase(test2[i]);
		t2 += test2[i]; 
	}
	if(size1 > size2){
		firsthalf = t1;
		secondhalf = t2;
	}
	else{
		firsthalf = t2;
		secondhalf = t1;
	}

	for(int j = 0; j < secondhalf.length(); j++){
		int c1 = 0;
		int c2 = 0;
		char item = secondhalf[i];
		for(int i = 0; i < secondhalf.length(); i++){
			if(item == secondhalf[i]){
				c2++;
			}
		}	
		for(int t = 0; t < firsthalf.length(); t++){
			if(item == firsthalf[i]){
				c1++;
			}	
		}
		if(c2 > c1){
			return false;
		}
	}
return true;
	
}

//DONE add a word to the vector. return false if failed true if succeed
bool FindPalindrome::add(const string & value)
{

int plength = plndr.size();
int vlength = value.length();
// first we must check that the string contains only alphabet chars
for( int i = 0; i < vlength; i++){
	if(!isalpha(value[i])){
		return false;
	}
}

string s1 = value;
convertToLowerCase(s1);

//DONE second we must determine that the string does not already exist in the vec
for(int j = 0; j < plength; j++){
	string s2 = plndr[j];
	convertToLowerCase(s2);
	 if(s1 == s2){
		return false;
	 }
}
//third, we must call the findpalindrome function to ensure that the addition of this word will still make a palindrome
numpal = 0;
plndr.push_back(value);
recursiveFindPalindromes(plndr, emptyvec);
return true;

}

//add a vector. return false if failed and true if succeed
bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

//Returns a vector of vectors containing all palindromes.
vector< vector<string> > FindPalindrome::toVector() const
{
	//vector<vector<string>> returnThingie;
	//palcount = returnThingie;
	return palcount;

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