#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
        if (list.getLength() <= 1) {
        // List is already sorted or empty
        return list;
    }

    bool swapped;
    do {
        swapped = false;
        //Node<T>* curr = list.getHead();
        Node<T>* curr = list.getEntry(1);
        Node<T>* prev = nullptr;

        while (curr->getNext() != nullptr) {
            if (curr->getItem() > curr->getNext()->getItem()) {
                // Swap adjacent nodes
                Node<T>* temp = curr->getNext();
                curr->setNext(temp->getNext());
                temp->setNext(curr);
                if (prev != nullptr) {
                    prev->setNext(temp);
                } else {
                    //list.setHead(temp);
                    list.setEntry(1, temp);
                }
                prev = temp;
                swapped = true;
            } else {
                prev = curr;
                curr = curr->getNext();
            }
        }
    } while (swapped);

    return list;
}


#endif