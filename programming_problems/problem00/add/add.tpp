#include "add.hpp"

template <typename T> Add<T>::Add() {}

template <typename T> Add<T>::~Add() {}

template <typename T> T Add<T>::call(T arg1, T arg2) const { 
  T sum;
  sum = arg1 + arg2;
  return sum;
}
