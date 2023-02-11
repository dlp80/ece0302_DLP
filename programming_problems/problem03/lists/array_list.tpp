#include "array_list.hpp"

//constructor
template <typename T>
ArrayList<T>::ArrayList() {
  size = 0;
  arr = new T [size];
}

//destructor
template <typename T>
ArrayList<T>::~ArrayList() {
  if (arr != nullptr){
  delete[] arr;
  arr = nullptr;
  }
}

//copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){
size = rhs.size;
arr = new T[size];
 for (int i; i < size; i++){
  arr[i] = rhs.arr[i];
 }
}

//equal operator overload
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
  if (this != &rhs) {
    delete[] arr;
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
      arr[i] = rhs.arr[i];
    }
  }
  return *this;
}

//swap items in the array
template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {
  std::swap(size, rhs.size);
  //std::swap(capacity, rhs.capacity);
  std::swap(arr, rhs.arr);
}

//determine if arr is empty
template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
    if (size == 0){
    return true;
  }
  else{
    return false;
  }
}

//return size variable
template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return size;
}

//insert at location > false if no insert or invalid position
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if (position > size || position < 0) {
    return false;
  }
else{
  T* new_arr = new T[size + 1];
  for (std::size_t i = 0; i < size; i++) {
    new_arr[i] = arr[i];
  }
  delete[] arr;
  arr = new_arr;

  // Shift the elements after the insertion position to the right
  for (std::size_t i = size; i > position; i--) {
    arr[i] = arr[i - 1];
  }

  // Insert the item at the specified position
  arr[position] = item;
  size++;

  return true;
  }
}

//remove a var from the arr
template <typename T>
bool ArrayList<T>::remove(std::size_t position){
    temp = new T[size-1];

  int j = 0;
  
  for(int i = 0; i < size; i++){
    if (position != i){
      temp[j] = arr[i];
      j++;
    }
    if (position == i){
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

//clr array
template <typename T>
void ArrayList<T>::clear() {
  for (int i; i <size; i++){
    remove(i);
  }
  size = 0;
}

//return the entry @ position
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
    for(int i = 0; i < size; i++){
    if (position == i){
      return T(arr[i]);
    }
  }
}

//set value @ that position
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
    for(int i = 0; i < size; i++){
    if (position == i){
      arr[i] = newValue;
    }
  }
}
