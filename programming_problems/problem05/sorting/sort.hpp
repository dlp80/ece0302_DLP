#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
    //case where contents = 0 or 1
    std::size_t n = list.getLength();
    if (n <= 1) {
        return list;
    }

    // Bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (std::size_t i = 1; i < (n-1); ++i) {
            T item1 = list.getEntry(i);
            T item2 = list.getEntry(i+1);
            if (item1 = item2) {
                list.setEntry(i, item2);
                list.setEntry(i+1, item1);
                swapped = true;
            }
        }
        --n;
    }

    return list;
}

#endif

