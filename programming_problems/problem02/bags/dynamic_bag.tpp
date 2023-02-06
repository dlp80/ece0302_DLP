#include "dynamic_bag.hpp"

//default constructor
template<typename T>
DynamicBag<T>::DynamicBag() {
  size = 0;
  arr = new T [size];
}

//copy constructor
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
size = x.size;
arr = new T[size];
 for (int i; i < size; i++){
  arr[i] = x.arr[i];
 }
}

//destructor
template<typename T>
DynamicBag<T>::~DynamicBag(){
  if (arr != nullptr){
  delete[] arr;
  arr = nullptr;
  }
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  if (this != &x) {
    delete[] arr;
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
      arr[i] = x.arr[i];
    }
  }
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  std::swap(size, x.size);
  std::swap(arr, x.arr);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  temp = new T[size + 1];
  for(int i = 0; i < size; i++){
    temp[i] = arr[i];
  }

  temp[size] = item;
  size = size + 1;
  delete[] arr;

  arr = temp;

 for(int j = 0; j<size; j++){
  if(arr[j] == item){
    return true;
  }
 }
 return false;
  
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  /* operating steps:
  1 - allocate size for temp, 
  2 - traverse the array checking for equality
  3 - once you get to the thing u are looking to remove
  fill new array with stuff up until that index
  4 - skip over that item then fill array with stuff after
  the specified index */

  temp = new T[size-1];

  int j = 0;
  
  for(int i = 0; i < size; i++){
    if (item != arr[i]){
      temp[j] = arr[i];
      j++;
    }
    if (item == arr[i]){
      continue;
    }

  }
  if (j == size) {
    return false;
  }
  
  delete[] arr;
  arr = temp;
  size--;
  return true;
}


template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if (size == 0){
    return true;
  }
  else{
    return false;
  }
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{

  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for(int i; i < size; i++){
    if (arr[i] != item){
      return false;
    }
  }
  return true;
}

template<typename T>
void DynamicBag<T>::clear(){
  for (int i; i <size; i++){
    remove(i);
  }
  size = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t count =0;
  for(int i =0; i < size; i++){
    if (arr[i] == item){
      count = count + 1;
    }
  }
  return count;
}
