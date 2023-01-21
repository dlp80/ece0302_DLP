#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{

  public:

  //creates standard array of size 8
  Bitset();

  //creates custom array of size N (user input)
  Bitset(intmax_t size);

  //creates array based on string input
  Bitset(const std::string & value);

  //destructor
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // this function returns the size of the array
  intmax_t size() const;

  // boolean function to determine if bitset is valid
  bool good() const;

  //this function sets a certain value to 1
  void set(intmax_t index);

  //this function sets a certain value to 0
  void reset(intmax_t index);

  //toggle a certain value to be either 1 or 0
  void toggle(intmax_t index);

  //check if the nth bit == 1 or not
  bool test(intmax_t index);

  //converts array num2str
  std::string asString() const;

  private:
  int *customArray = nullptr;
  bool validity;
  int count;
  

};

#endif
