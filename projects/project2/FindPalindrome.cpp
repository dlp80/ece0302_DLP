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

//------------------- PRIVATE CLASS METHODS ------------------------------------

// DONE private recursive function. Must use this signature!
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
			palvec.push_back(currentStringVector); //return of last function
        }}
        // Print the current combination
        /*for (const auto& str : currentStringVector) {
            cout << str << " ";
        }
        cout << endl;*/
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
				if(cutTest2(candidateStringVector, currentStringVector)){ //cutTest2?
                	recursiveFindPalindromes(candidateStringVector, currentStringVector);
				}
                currentStringVector.pop_back();
            }
        }
    }
}

// DONE private function to determine if a string is a palindrome (given, you
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


//DONE
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
	//vector of vectors
	palvec = vector<vector<string>>();

}
//DONE
FindPalindrome::~FindPalindrome()
{
	clear();
}

//DONE Returns the current number of sentence palindromes in the
//FindPalindrome instance.
int FindPalindrome::number() const
{
    return numpal;
}

//DONE clears all elements from the vector
void FindPalindrome::clear()
{
	palcount.clear();
	plndr.clear();
	palvec.clear();
	numpal = 0;
}

//DONE see instructions for deliverable
bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
    // initialize variables
	//NOTE!! implement check for duplicate within the vector they pass
	//you will need to make sure one letter is not counted many times. 
	//1 - convert to lowercase + squish vector into a string !!!!
	//2 - check if alphabet only !!!!
	//3 - check occurence. increment count. if count odd > increment odd count. if odd count > 1 EVER! immediately break
	
	vector<string> temp = stringVector;
	string storage;
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for(int i=0; i < temp.size(); i++){
		storage += temp[i];
	}
	
	for(int i=0; i < storage.length(); i++){
		if(!isalpha(storage[i])){
			return false;
		}
	}
	convertToLowerCase(storage);
	int count = 0;
	int oddCount = 0;
	
	for(int i = 0; i < alphabet.length(); i++){
		for(int j = 0; j < storage.length(); j++){
			if(alphabet[i] == storage[j]){
				count++;
			}
		}
	if((count%2) != 0){
		oddCount++;
	}
	count = 0;
}
if(oddCount > 1){
		return false;
	}

return true;

//
}

//DONE see instructions for deliverable
bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<string>temp1 = stringVector1;
	vector<string>temp2 = stringVector2;
	int count1, count2;
	string string1, string2, bigger, smaller;


	//turn vector 1 into string 1, 
	//turn vector 2 into string 2
	//assign to small and big strings
	//convert big string and small string to LC
	
	for(int i = 0; i < temp1.size(); i++){
		string1 += temp1[i];
	}
	for(int i = 0; i < temp2.size(); i++){
		string2 += temp2[i];
	}
	if(string1.size() > string2.size()){
		bigger = string1;
		smaller = string2;
	}
	else{
		bigger = string2;
		smaller = string1;
	}

	convertToLowerCase(bigger);
	convertToLowerCase(smaller);

	//loop through all chars -- zero out count1/2 at the start
	//count number of times char occurs in small str
	//count number of times char occurs in big str - these 2 are separate for loops within the loop through all chars. 
	//if smallstr has more of a given char return false
	for(int i = 0; i < alphabet.size(); i++){
		count1 = 0;
		count2 = 0;
		for(int j = 0; j < smaller.size(); j++){
			if(alphabet[i] == smaller[j]){
				count1++;
			}
		}
		for(int j = 0; j < bigger.size(); j++){
			if(alphabet[i] == bigger[j]){
				count2++;
			}
		}
	if(count1>count2){
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

//second we must determine that the string does not already exist in the vec
for(int j = 0; j < plength; j++){
	string s2 = plndr[j];
	convertToLowerCase(s2);
	 if(s1 == s2){
		return false;
	 }
}
//third, we must call the findpalindrome function to ensure that the addition of this word will still make a palindrome
numpal = 0;
palcount.clear();
palvec.clear();
plndr.push_back(value);
if(cutTest1(plndr)){
	recursiveFindPalindromes(plndr, emptyvec);
}
return true;

}

//DONE add a vector. return false if failed and true if succeed
bool FindPalindrome::add(const vector<string> & stringVector)
{
	vector<string> ttvec = stringVector;
	string test;
	int size = stringVector.size();
	int duplicate=0;
	vector<string> tempVec = stringVector;

	//convert to lower > merge into a string, test > check isalpha for all members
	for(int i =0; i<size; i++){
		convertToLowerCase(ttvec[i]);
	}
	for(int i = 0; i < size ; i++){
		test += stringVector[i];
	}
	convertToLowerCase(test);
	for( int i = 0; i < test.length(); i++){
	if(!isalpha(test[i])){
		return false;
		}
	}
	
	//internally check that the vector does not contain duplicates
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){
			if(ttvec[i] == ttvec[j]){
				return false;
			}
		}
	}

	vector<string> testplndr = plndr;
	for(int i=0; i<testplndr.size(); i++){
	convertToLowerCase(testplndr[i]);
	}

	//next we must determine that the string in the vector does not already exist in the vec
	for(int i = 0; i < plndr.size(); i++){
		for(int j = 0; j < size; j++){
			if((stringVector[i]==testplndr[j]) || (ttvec[i]==testplndr[i])){
				return false;
			}
			}
		}

////third, we must call the findpalindrome function to ensure that the addition of this word will still make a palindrome

for(int i =0; i < size; i++){
	plndr.push_back(stringVector[i]);
}

numpal = 0;
palcount.clear();
//palvec.clear();

if(cutTest1(plndr)){ //we need to ! it for it to work
	recursiveFindPalindromes(plndr, emptyvec);
}
return true;
}

//DONE Returns a vector of vectors containing all palindromes.
vector< vector<string> > FindPalindrome::toVector() const
{
	//TODO
	//vector<vector<string>> returnThingie;
	return palvec;
	//return palcount; //returning what????

}
