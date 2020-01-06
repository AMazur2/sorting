#ifndef SHELLSORT_CPP_BUBBLESORT_HPP
#define SHELLSORT_CPP_BUBBLESORT_HPP


#include <algorithm>
#include <string>

template <typename IteratorType>
void bubbleSort(IteratorType first, IteratorType last)
{
    IteratorType current;
    IteratorType next;
    bool swapped = true;
    while (swapped)
    {
        current = first;
        swapped = false;
        next = first;
        ++next;
        for(; current != last; ++current)
        {
            if( *current > *next )
            {
                swap(*current, *next);
                swapped = true;
            }
            ++next;
        }
        --last;
    }
}

#endif //SHELLSORT_CPP_SELECTIONSORT_H
