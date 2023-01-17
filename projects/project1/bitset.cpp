#include "bitset.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>


//use the "new" notation and use custom array as a ptr instead -- put all of this in the .hpp file


//creates standard array of size 8
Bitset::Bitset() {
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
    if ((value[i] != '0') || (value[i] != '1')){
       std::cout << "ERR! Bitset is invalid";
       break;
        }
    else{
     int *customArray = new int[value.size()];
     }
  }  
}

Bitset::~Bitset() {
    // TODO
}
Bitset::Bitset(const Bitset & ) = delete;
Bitset & operator=(const Bitset &) = delete;

/////////////////////////////////////////////////////////////
//end constructors and destructors
/////////////////////////////////////////////////////////////

intmax_t Bitset::size() const{ // this function returns the size of the array
  int count=0;
  for (int i=0; i < *customArray; i++ ){
    count++;
  }
  return count;
}


bool Bitset::good() const{ // boolean function to determine if bitset is valid
  bool choice;
  int len = size();
  for (int i=0; i < len; i++){
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
  return choice;
}


void Bitset::set(intmax_t index){ // sets a certain element to 1
  if ((index <= size()) && (index >= 0)){
    customArray[index-1] = 1 };
    good();
}


void Bitset::reset(intmax_t index){ // sets a certain element to 0
  if (index <= size())
    customArray[index-1] = 0;
    good();
}

void Bitset::toggle(intmax_t index){ //toggle a certain value to be either 1 or 0
  if (index <= size())
    if(customArray[index] == 0){
      customArray[index] = 1;
      good();
      }
    else if(customArray[index] == 1){
      customArray[index] = 0;
      good();
      }
}

bool Bitset::test(intmax_t index){
  if(customArray[index] == 1){
    return true;
  }
  elseif((customArray[index] == 1) || ((index < 0) && index > (customArray-1))){
  return false;
  }
}

  
std::string Bitset::asString() const{
  std::stringstream arrStr;

}


}


