
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
	return (currentSize==0);
	/*if (currentSize == 0){
		return true;
	}
	else{
		return false;
	}*/
}  // end isEmpty

// DONE: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
	/*int empty = 0;
	if(isEmpty()){
		return empty;
	}
	else{
		return currentSize;
	}*/
}  // end size

//DONE Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem){
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, headPtr);
	/*if(newNodePtr == nullptr){
		return false;
	}*/
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
	if(currentSize == 0){
		throw logic_error("stack is empty");
	}
	else{
		ItemType returnItem;
		returnItem = headPtr->getItem();
		return returnItem;
	}
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
	int n = currentSize;
	for (int i = 0;i<n;i++){
		pop();
	}
	currentSize = 0;
}  // end clear

