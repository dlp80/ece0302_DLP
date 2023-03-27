#include "queue.hpp"

  // enqueue (add) newEntry into the queue back
  // throw exception if not possible
template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
	//push implementation from stack
	Node<T>* newNodePtr = new Node<T>(item, headPtr);

	headPtr = newNodePtr;
	newNodePtr = nullptr;
	//increment size counter
	currentSize++;
}

  // dequeue (remove) newEntry from the queue front
  // throw exception if not possible
template <typename T, typename L>
void Queue<T,L>::dequeue()
{

	if(!isEmpty()){
		//if stack is not empty, delete top
		Node<T>* nodeToDelPtr = headPtr;
		headPtr = headPtr->getNext();

		//return deleted node to system
		nodeToDelPtr->setNext(nullptr);
		delete nodeToDelPtr;
		nodeToDelPtr = nullptr;
		//decrement size counter
		currentSize--;
	}

}

  // return a copy of the item at the front of the queue
  // throw exception if not possible
template <typename T, typename L>
T Queue<T,L>::peekFront()
{
	if(currentSize != 0){
		T returnItem;

		Node<T>* temp = headPtr;

		for(int i = 0; i<(currentSize-1); i++){ //check indexing -size
			temp = temp->getNext();
		}

		returnItem = temp->getItem();
		return returnItem;
	}
	Node<T>* temp = nullptr; //readjusting memory
}

//return true if the Q isEmpty
template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
	return (currentSize==0);
}

