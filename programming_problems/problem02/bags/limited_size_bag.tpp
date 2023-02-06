#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  size = 0;
  arr = new T [size];
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
if(size < maxsize){
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
else{
    return false;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
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
bool LimitedSizeBag<T>::isEmpty() const
{
  if (size == 0){
    return true;
  }
  else{
    return false;
  }
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
    for(int i; i < size; i++){
    if (arr[i] != item){
      return false;
    }
  }
  return true;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  for (int i; i <size; i++){
  remove(i);
  }
  size = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t count =0;
  for(int i =0; i < size; i++){
    if (arr[i] == item){
      count = count + 1;
    }
  }
  return count;
};
