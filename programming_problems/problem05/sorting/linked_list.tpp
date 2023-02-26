#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
 clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
   head = nullptr;
  tail = nullptr;
  size = 0;
  current = x.head;
  temp = nullptr;
  while (current != nullptr)
  {
    Node<T>* newNode = new Node<T>(current->getItem());
    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      temp->setNext(newNode);
    }
    temp = newNode;
    current = current->getNext();
    size++;
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  std::swap(head, x.head);
  std::swap(tail, x.tail);
  std::swap(size, x.size);

  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(head, x.head);
  std::swap(size, x.size);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if (head == nullptr){ 
  return true;
  }
  else{
  return false;
  }

}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //must traverse until the current ptr = null which indicates end of LL
  std::size_t count = 0;
  Node<T> *curr;
  curr = head;
  while (current != nullptr){
    count++;
    curr = curr->getNext();
  }
  return count;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
    if (position > size) {
    return false;
  }

  current = head;
  temp = new Node<T>(item);
  if (position == 0) {
    temp->setNext(head);
    head = temp;
  } 
  else {
    for (std::size_t i = 0; i < position - 1; ++i) {
      current = current->getNext();
    }
  temp->setNext(current->getNext());
  }

  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
    if (position == 0) {
    temp = head;
    head = head->getNext();
    delete temp;
    return true;
  }

  Node<T> *prev = head;
  for (std::size_t i = 0; i < position - 1; i++) {
    prev = prev->getNext();
    if (prev == nullptr) {
      return false;
      }
    }

  current = prev->getNext();
  if (current == nullptr) {
    return false;
  }

  prev->setNext(current->getNext());
  delete current;
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
    while(!isEmpty())
    remove(1);
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if (position >1 && position < getLength()){
    Node<T> *current = head;
  for (std::size_t i = 1; i < position; i++) {
    current = current->getNext();
  }
}
  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
    // Check if the position is within the bounds of the linked list
  if (position >= size) {
    throw std::out_of_range("The position is out of range.");
  }

  // Find the node at the specified position
  current = head;
  for (std::size_t i = 0; i < position; ++i) {
    current = current->getNext();
  }

  // Set the value of the node
  current->setItem(newValue);
}
