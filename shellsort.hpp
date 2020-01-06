#ifndef SHELL_HPP
#define SHELL_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include "bubblesort.hpp"

/*
int increament( int upperbound )
{
    int i;
    for( i = 1; i < upperbound; ++1 ){
        i = 3 * ( i -1 );
    }

    return i;

}
*/

template<typename IteratorType>
void shellSort( IteratorType first, IteratorType last)
{
    std::vector<int> steps {1, 4, 13, 40, 121, 364, 1093, 3280 };
    int len = last - first;
    int incInd = 0;
    for( int i = steps.size() - 1; i >= 0; --i) {
        if ( steps[i] < len ) {
            incInd = i;
            break;
        }
    }

    for( int i = incInd; i >= 0; --i){
        bubbleSort(first, last); // to jest z jakiegoś pliku
    }
}

#endif