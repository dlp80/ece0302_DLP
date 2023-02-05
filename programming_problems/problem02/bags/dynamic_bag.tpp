#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  size = 0;
  arr = new T [size];
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
size = x.size;
arr = new T[size];

 for (int i; i < size; i++){
  arr[i] = x.arr[i];
 }

}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete[] arr;
  arr = nullptr;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  y = x.y;
  z = x.z; 
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  temp = new T[size + 1];
  for(int i; i<(size); i++){
    temp[i] = arr[i];
  }
  size = size+1;
  temp[size] = item;
  delete[] arr;

  arr = temp; //**
  if (arr[size] == 0){
    return false;
  }
  else{
    return true;
  }
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
  for(int i; i<size; i++){
    if (item == arr[i]){
       for(int j; j<i; j++){
    temp[j] = arr[j];
      }
  for(int n; n>i; n++){
    temp[n] = arr[n];
      }
    }
  }
  return false;
}


template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
    for(int i; i<size; i++){
    if (item == arr[i]){
      return true;
    }
    else{
      return false;
    }
  }
}

template<typename T>
void DynamicBag<T>::clear(){
  delete[] arr;
  arr = nullptr;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
