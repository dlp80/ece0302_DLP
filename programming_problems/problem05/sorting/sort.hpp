#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
    int n = list.getLength();

    // If list is empty or has only one element, return the list
    if (n <= 1) {
        return list;
    }

    // Perform bubble sort algorithm
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;

        // Traverse the list from beginning to end
        Node<T>* current = list.getNodeAt(1);
        Node<T>* previous = nullptr;

        for (int j = 0; j < n-i-1; j++) {
            Node<T>* next = current->getNext();

            if (current->getItem() > next->getItem()) {
                // Swap the elements
                if (previous == nullptr) {
                    list.setEntry(1, next);
                    current->setNext(next->getNext());
                    next->setNext(current);
                    previous = next;
                    swapped = true;
                } else {
                    previous->setNext(next);
                    current->setNext(next->getNext());
                    next->setNext(current);
                    previous = next;
                    swapped = true;
                }
            } else {
                previous = current;
                current = next;
            }
        }

        // If no elements were swapped, the list is sorted
        if (!swapped) {
            break;
        }
    }

    return list;
}


#endif