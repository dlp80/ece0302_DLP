#include "list.hpp"

template <typename T>
List<T>::List() : itemCount(0)
{
  //TODO
  //headPtr = nullptr;
  //itemCount = 0;
}

template <typename T>
List<T>::~List()
{
  //TODO
  clear();
}

template <typename T>
List<T>::List(const List<T>& x)
{
  //TODO
  CAP=x.CAP;
  itemCount=0;
  for(size_t i = 1; i <= x.itemCount;i++)
  {
    insert(i, x.getEntry(i));
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  //TODO
	swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  //TODO
  CAP=x.CAP;
  itemCount=0;
  for(size_t i = 1; i <= x.itemCount;i++)
  {
    insert(i, x.getEntry(i));
  }
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  //TODO
  //return true;
  return (itemCount == 0);
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  //TODO
  //return 0
  return itemCount;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  //TODO
  itemCount++;
  if (itemCount==(CAP) || itemCount<0)
  {
    return false;
  }
  else
  {
    arr[position]=item;
  }
  return true;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  //TODO
  if(itemCount<=1)
  {
    return false;
  }
  for (size_t i = position; i<=itemCount;i++)
  {
    arr[i]=arr[i+1];
  }
  return true;
}

template <typename T>
void List<T>::clear()
{
  //TODO
  itemCount=0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  //TODO
  //return T();
  return arr[position];
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
  arr[position]=newValue;
}

/*
template <typename T>
Node<T>* List<T>::getNodeAt(std::size_t position) const
{
	//This traverses the list and returns the node at position
	Node<T>* curPtr = headPtr;
	for (std::size_t next = 0; next < position; next++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
} //end getNodeAt */