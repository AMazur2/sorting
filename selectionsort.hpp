#include <algorithm>
#include <string>

template<typename IteratorType>
void selectionSort(IteratorType first, IteratorType last, unsigned int step = 1)
{
    IteratorType minIndex = first;
    IteratorType actualIndex = first + 1;
    while( first < last ){
        minIndex = first;
        actualIndex = first + 1;
        while( actualIndex < last ){
            if ((*actualIndex).compare(*minIndex) < 0) {
                minIndex = actualIndex;
            }

            actualIndex += step;
        }

        std::iter_swap(first, minIndex);
        first += step;
    }
}