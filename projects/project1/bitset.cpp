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
    if (count != 8){
      validity = false;
    }
}

//creates custom array of size N (user input)
Bitset::Bitset(intmax_t size) {
count = size;
if ((size >= 0) && (size <= 64)){
customArray = new int[size];
  for (int i=0; i < size; i++){
    customArray[i] = 0;
    }
   }
  else{
    validity = false;
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
  if ((index <= count-1) && (index >= 0)){
    customArray[index] = 1;
    validity = true;
  }
  else{
    validity = false;
     }
  }

//this function sets a certain value to 0
void Bitset::reset(intmax_t index){
  if ((index <= count-1) && (index >= 0)){
    customArray[index] = 0;
    validity = true;
  }
  else{
    validity = false;
  }
}

//toggle a certain value to be either 1 or 0
void Bitset::toggle(intmax_t index){ 
  if ((index <= (count-1)) && (index >= 0)){
    if(customArray[index] == 0){
        customArray[index] = 1;
        validity = true;
      }
    else if(customArray[index] == 1){
      customArray[index] = 0;
      validity = true;
      }
    }
  else if ((index < 0) || (index > (count-1))){
    validity = false;
  }
}

//check if the nth bit == 1 or not
bool Bitset::test(intmax_t index){
if ((index <= count-1) && (index >= 0)){
  if(customArray[index] == 1){
    validity = true;
    }
  else if((customArray[index] ==0) || ((index < 0) && index > (size()))){
    validity = false;
    }
}
else{
  validity = false;
}
  return validity;
}

//converts array num2str
std::string Bitset::asString() const{
  std::string ss = "";
  for (int i = 0; i < count; i++) {
        ss += std::to_string(customArray[i]);
      }
  
  return ss;
}


