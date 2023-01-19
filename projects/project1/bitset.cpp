#include "bitset.hpp"
#include <iostream>
#include <string>
//using namespace std;


//use the "new" notation and use custom array as a ptr instead -- put all of this in the .hpp file
//good function should just return the validity var but each individual fxn should internally error check

//creates standard array of size 8
Bitset::Bitset(){
  count = 8;
  customArray = new int[8];
    for (int i=0; i < 8; i++){
        customArray[i] = 0;
    }
    validity = true;
}

//creates custom array of size N (user input)
Bitset::Bitset(intmax_t size) {
count = size;
if (size >= 0){
customArray = new int[size];
  for (int i=0; i < size; i++){
    customArray[i] = 0;
    }
  }
  //error checking for loop
  for (int i=0; i < size; i++){
    if(customArray[i]=!0)
    validity = false;
    //std::cout << "ERR! Bitset is invalid";
    }
}

//creates array based on string input
Bitset::Bitset(const std::string & value) {
  count = value.length();
  customArray = new int[count];
  for (int i=0; i < count; i++){
    if ((value[i] == '0') || (value[i] == '1')){
     customArray[i] = value[i] - '0';
    }
    else{
      validity = false;
      //std::cout << "ERR! Bitset is invalid";
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
  return count;
}

// boolean function to determine if bitset is valid
bool Bitset::good() const{
  return validity;
}

//this function sets a certain value to 1
void Bitset::set(intmax_t index){
  if ((index <= count) && (index >= 0)){
    validity = true;
    customArray[index] = 1;
  }
  else{
    validity = false;
     }
  }

//this function sets a certain value to 0
void Bitset::reset(intmax_t index){
  if (index <= count){
    customArray[index] = 0;
  }
  else{
    validity = false;
  }
}

void Bitset::toggle(intmax_t index){ //toggle a certain value to be either 1 or 0
  if (index <= count){
    if(customArray[index] == 0){
        customArray[index] = 1;
      }
    else if(customArray[index] == 1){
      customArray[index] = 0;
    }
    else{
      validity = false;
    }
  }
}

//check if the nth bit == 1 or not
bool Bitset::test(intmax_t index){
  if(customArray[index] == 1){
    validity = true;
    }
  else if((customArray[index] == 1) || ((index < 0) && index > (size()-1))){
    validity = false;
    }
  return validity;
}

std::string Bitset::asString() const{
  std::string ss = "";
  for (int i = 0; i < count; i++) {
        ss += std::to_string(customArray[i]);
      }
  
  return ss;
}


