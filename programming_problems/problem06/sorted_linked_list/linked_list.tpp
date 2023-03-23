#include "linked_list.hpp"

//DONE
template <typename T>
LinkedList<T>::LinkedList()
{
  headPtr = nullptr;
  itemCount = 0;
}

//DONE
template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

//DONE
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
    itemCount = x.itemCount;
  Node<T>* origPtr = x.headPtr;
	//check if original is empty, if so make copy empty
	if (origPtr == nullptr) 
		headPtr = nullptr;
	else {
		//make copy of first node
		headPtr = new Node<T>();
		headPtr -> setItem(origPtr -> getItem());
		//copy remaining nodes
		Node<T>* newPtr = headPtr; 
		origPtr = origPtr -> getNext();
		while (origPtr != nullptr) {
			//get next item in list, and make new node with item, and link
			T nextItem = origPtr -> getItem();
			Node<T>* newNodePtr = new Node<T>(nextItem);
			newPtr -> setNext(newNodePtr);
			//shift pointers
			newPtr = newPtr -> getNext();
			origPtr = origPtr -> getNext();
		} // end while
	} // end if
} //end copy constructor

//DONE
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
	swap(x);
	return *this;
} //end operator overload

//DONE
template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
	std::swap(itemCount, x.itemCount);
	std::swap(headPtr, x.headPtr);
}//end swap

//DONE
template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (itemCount == 0);
}

//DONE
template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return itemCount;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
	    // Insert the item at the specified position in the linked list
    if (position > itemCount + 1 || position < 0) {
        throw std::out_of_range("position out of range.");
    }
    Node<T>* newNode = new Node<T>(item);
    if (position == 0) {
        newNode->setNext(headPtr);
        headPtr = newNode;
    } else {
        Node<T>* prev = getNodeAt(position - 1);
        newNode->setNext(prev->getNext());
        prev->setNext(newNode);
    }
    itemCount++;
	/*if ((position >= 0) && (position <= itemCount)) {
		Node<T>* newNodePtr = new Node<T>(item);
		if (position == 0) {
			newNodePtr -> setNext(headPtr);
			headPtr = newNodePtr;
		}
		else {
			Node<T>* prevPtr = getNodeAt(position-1);
			newNodePtr -> setNext( prevPtr -> getNext() );
			prevPtr -> setNext( newNodePtr );
		}
		itemCount++;
	} */
} //end insert

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
	if(isEmpty()){
		throw(std::range_error("error! out of range"));
	}
	else if ((position >= 0) && (position < itemCount)) {
		Node<T>* curPtr = nullptr;
		if (position == 0) {
			curPtr = headPtr;
			headPtr = headPtr -> getNext();
		}
		else {
			Node<T>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr -> getNext();
			prevPtr -> setNext( curPtr -> getNext() );
		}
		delete curPtr;
		itemCount--;
	} 
	else if (position < 0){
		throw(std::range_error("error! out of range"));
	}
}


template <typename T>
void LinkedList<T>::clear()
{
	while (!isEmpty())
	remove(0);
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
	if(isEmpty()){
		throw(std::range_error("error! out of range"));
	}

	else if ((position >= 0) && (position < itemCount)) 
	{
		return getNodeAt(position)->getItem();
	}
	else throw(std::range_error("error! out of range"));
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
	if(isEmpty()){
		throw(std::range_error("error! out of range"));
	}
	else if ((position >= 0) && (position < itemCount)) 
	{
		Node<T>* node = getNodeAt(position);
		node->setItem(newValue);
	}
	else{
		throw(std::range_error("error! out of range"));
	}
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(std::size_t position) const
{
	//This traverses the list and returns the node at position
	Node<T>* curPtr = headPtr;
	for (std::size_t next = 0; next < position; next++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
} //end getNodeAt

