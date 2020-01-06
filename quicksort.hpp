#include <iostream>
#include <vector>
#include <algorithm>

template <typename IteratorType>
auto partition(IteratorType beg_it, IteratorType end_it)
{
    auto partition_indx = beg_it;
    for( auto i = beg_it; i != end_it; i++){
        if(*i <= *end_it){
            std::iter_swap( i, partition_indx);
            partition_indx++;
        };
    }
    std::iter_swap(partition_indx, end_it);
    return partition_indx;
}


template <typename IteratorType>
void qsort(IteratorType beg_it, IteratorType end_it)
{
    int size = std::distance( beg_it, end_it );
    if (size <= 1 ) return;
    auto partition_indx = partition( beg_it, end_it );
    qsort( beg_it, partition_indx-1);
    qsort( partition_indx, end_it );
}
 