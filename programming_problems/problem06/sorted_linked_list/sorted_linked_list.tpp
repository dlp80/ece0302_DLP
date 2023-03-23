#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T> //NA
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
    // Create a copy of the unsorted list using the LinkedList copy constructor
    LinkedList<T> sorted_list(unsorted_list);
    
    // Use bubble sort to sort the list in ascending order
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (std::size_t i = 1; i < sorted_list.getLength(); i++) {
            if (sorted_list.getEntry(i) > sorted_list.getEntry(i + 1)) {
                T temp = sorted_list.getEntry(i);
                sorted_list.setEntry(i, sorted_list.getEntry(i + 1));
                sorted_list.setEntry(i + 1, temp);
                swapped = true;
            }
        }
    }
    
    // Copy the sorted list to the SortedLinkedList
    for (std::size_t i = 1; i <= sorted_list.getLength(); i++) {
        LinkedList<T>::insert(i, sorted_list.getEntry(i));
    }
}

template <typename T> //NA
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T> //NA
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T> //NA
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T> //NA
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T> //NA
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T> //NA
void SortedLinkedList<T>::insert(const T& item)
{
  //Node<T>* pt1 = new Node<T>(item);
  if(!isEmpty()){
  LinkedList<T>::insert(getLength(), item);
  }
  else{
    LinkedList<T>::insert(0, item);
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()){
    throw std::range_error("empty list in remove");
  } 
  else{
    for(std::size_t i; i < getLength(); i++){
      if(getEntry(i) == item){
        remove(i);
      }
    }
  }
  
  // TODO
}

//done?
template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()){
     throw std::range_error("empty list in remove");
  }
  
  else if(position >= 0 && position < getLength()){
    LinkedList<T>::remove(position);
  }
  else if (position < 0 || position >= getLength()){
     throw std::range_error("out of bounds");
  }
}

template <typename T> //NA
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T> //NA
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  if(isEmpty()){
     throw std::range_error("empty list");
  }
  
  else if(position >= 0 && position < getLength()){
    LinkedList<T>::getEntry(position);
  }
  else if (position < 0 || position >= getLength()){
     throw std::range_error("out of bounds");
  }

}

//done?
template <typename T> //possibly done
long int SortedLinkedList<T>::getPosition(const T& item)
{
  getLength();
  for(long int i = 0; i < getLength(); i++){
    if(item == getEntry(i)){
        return i;
    }
  }
  return -1; //do we need to throw an error?
}
