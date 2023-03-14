
//adt stack implementations
#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

//DONE: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack()
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

//DONE: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack(){
	while(!isEmpty())
	pop();
}  // end destructor

//DONE: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const{
	return headPtr == nullptr;
}  // end isEmpty

// DONE: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	if(isEmpty()){
		return 0;
	}
	else{
		return currentSize;
	}
}  // end size

//DONE Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem){
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, headPtr);
	if(newNodePtr == nullptr){
		return false;
	}
	headPtr = newNodePtr;
	newNodePtr = nullptr;
	//increment size counter
	currentSize++;
	return true;
	
}  // end push

//DONE Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
    if (!isEmpty()) {
        return headPtr->getItem();
    }
    else {
        // Return a default-constructed ItemType object if stack is empty
        return ItemType{};
    }	

	/*ItemType returnItem;
	while(!isEmpty()); {//enforcing precondition during debugging
		returnItem = headPtr->getItem();
	}
	return returnItem;*/
}  // end peek

//DONE Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;
	if(!isEmpty()){
		//if stack is not empty, delete top
		Node<ItemType>* nodeToDelPtr = headPtr;
		headPtr = headPtr->getNext();

		//return deleted node to system
		nodeToDelPtr->setNext(nullptr);
		delete nodeToDelPtr;
		nodeToDelPtr = nullptr;
		//decrement size counter
		currentSize--;
		
		result = true;
	}
	return result;
}  // end pop

// DONE Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while(!isEmpty()){
		pop();
	}
}  // end clear

