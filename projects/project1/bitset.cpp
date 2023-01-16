#include "bitset.hpp"
//#include using namespace std;
#include <iostream>

class Bitset{
public:
//creates standard array of size 8
Bitset::Bitset() {
   int defaultArray[8];
    for (int i=0; i < 8; i++){
        defaultArray[i] = 0;
    }
}

//creates custom array of size N (user input)
Bitset::Bitset(intmax_t size) {
int customArray[size];
    for (int i=0; i < size; i++){
        customArray[i] = 0;
    }
    //error checking for loop
    for (int i=0; i < size; i++){
        if(customArray[i]=!0)
        std::cout << "FLAG ERR! Invalid array";
    }
  }


Bitset::Bitset(const std::string & value) {
    // TODO
}

Bitset::~Bitset() {
    // TODO
}
};

/////////////////////////////////////////////////////////////
/*


  // TODO COMMENT
  Bitset(const std::string & value);

  //destructor to deallocate memory. safeguard!!
  ~Bitset();

  //this code defines the copy constructor and deletes it
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // this function returns the size of the object created by the class
  //in this case, the size of the array
  intmax_t size() const;

  // boolean function that can be used to
  bool good() const;

  // sets a certain element to 1
  void set(intmax_t index){
    if (index <= size(customArray))
        customArray[index] = 1;
    else
    //bitset becomes invalid
  }

  // sets a certain element to 0
  void reset(intmax_t index){
    if (index <= size(customArray))
      customArray[index] = 0;
    else
    //bitset becomes invalid
  }


  // TODO COMMENT
  void toggle(intmax_t index){
    if (index <= size(customArray))
      if(customArray[index] = 0){
        customArray[index] = 1;}
      elseif(customArray[index] = 1){
        customArray[index] = 0}
      }
    else
    //bitset becomes invalid
  }

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:

  //int defaultArray[8];
  //int customArray[];

}; */




// TODO: other methods*/
