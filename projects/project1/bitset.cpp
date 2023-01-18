#include "bitset.hpp"
#include <iostream>
#include <string>
using namespace std;

//use the "new" notation and use custom array as a ptr instead -- put all of this in the .hpp file

//creates standard array of size 8
Bitset::Bitset(){
  int *customArray = new int[8];
   if (good() == true)
    for (int i=0; i < 8; i++){
        customArray[i] = 0;
    }
}

//creates custom array of size N (user input)
Bitset::Bitset(intmax_t size) {
//place valid fxn here
int *customArray = new int[size];
  for (int i=0; i < size; i++){
    customArray[i] = 0;
    }
    //error checking for loop
  for (int i=0; i < size; i++){
    if(customArray[i]=!0)
      std::cout << "ERR! Bitset is invalid";
    }
}

//creates array based on string input
Bitset::Bitset(const std::string & value) {
  for (int i=0; i < value.size(); i++){
    if ((value[i] == '0') || (value[i] == '1')){
      int *customArray = new int[stoi(value)];
    }
    else{
      std::cout << "ERR! Bitset is invalid";
      break;
    }
  }
}

 Bitset::~Bitset(){
  delete[] customArray;
  customArray = nullptr;
 }


/////////////////////////////////////////////////////////////
//end constructors and destructors
/////////////////////////////////////////////////////////////

 // this function returns the size of the array
intmax_t Bitset::size() const{
  int count=0;
  for (int i=0; i < *customArray; i++ ){
    count++;
  }
  return count;
}

// boolean function to determine if bitset is valid
bool Bitset::good() const{
  bool choice;
  for (int i=0; i < size(); i++){
    if ((*customArray != 0) || (*customArray != 1)){
      std::cout << "ERR! Bitset is invalid";
      choice = false;
      break;
      }
    else if (*customArray <= 0){
      std::cout << "ERR! Bitset is invalid";
      choice = false;
    }
  else{
    choice = true;
  }
}
  choice = validity;
  return validity;
}

//this function sets a certain value to 1
void Bitset::set(intmax_t index){
  if ((index <= size()) && (index >= 0)){
    customArray[index-1] = 1;
    good();
  }
}

//this function sets a certain value to 0
void Bitset::reset(intmax_t index){
  if (index <= size()){
    customArray[index-1] = 0;
    good();
  }
}

void Bitset::toggle(intmax_t index){ //toggle a certain value to be either 1 or 0
  if (index <= size()){
    if(customArray[index] == 0){
        customArray[index] = 1;
        good();
      }
    else if(customArray[index] == 1){
      customArray[index] = 0;
      good();
    }
  }
}

//check if the nth bit == 1 or not
bool Bitset::test(intmax_t index){
  bool choice;
  if(customArray[index] == 1){
    choice = true;
    }
  else if((customArray[index] == 1) || ((index < 0) && index > (size()-1))){
    choice = false;
    }
  return choice;
}

std::string Bitset::asString() const{
  std::string arrStr;
  arrStr.assign(customArray, customArray+size());
  return arrStr;
}

