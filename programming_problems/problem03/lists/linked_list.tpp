#include "linked_list.hpp"

//default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  size = 0;

}

//destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
/*Node* curr = head;
  while (curr != nullptr) {
    Node* next = curr->next;
    delete curr;
    curr = next;*/
}


//copy constructor
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

//overload operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  std::swap(head, x.head);
  std::swap(tail, x.tail);
  std::swap(size, x.size);

  return *this;
}

//swap one node with another
template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(head, x.head);
  std::swap(size, x.size);
}

//determine if an entire list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{//traversing a singly linked list and only checking the first item will tell you everything
  if (head == nullptr){ 
  return true;
  }
  else{
  return false;
  }

}

//return the length of a linked list
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

//insert an item into a node at a certain position
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

//remove a certain item @ a position in the list
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

//clear the contents of the linked list
template <typename T>
void LinkedList<T>::clear()
{
  while(!isEmpty())
    remove(1);
}

// get a copy of the item at position
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

// set the value of the item at position
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
