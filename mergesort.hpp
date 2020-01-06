#include <iterator>
#include <vector>
#include <iostream>

template<typename Iter>
void merge(Iter beg, Iter mid, Iter end)
{
    std::vector<typename Iter::value_type> temp;
    temp.reserve(std::distance(beg, end));

    Iter left = beg;
    Iter right = mid;
    while (left != mid and right != end) {
        if (*right < *left) {
            temp.emplace_back(*right++);
        }
        else {
            temp.emplace_back(*left++);
        }
    }
    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, end);

    std::move(temp.begin(), temp.end(), beg);   
}

template<typename Iter>
void merge_sort(Iter beg, Iter end)
{

    int size = std::distance(beg, end);
    if (size <= 1) {
        return;
    }

    auto mid = std::next(beg, size / 2);
    // sort left half
    merge_sort(beg, mid);
    // sort right half
    merge_sort(mid, end);
    // merge halves
    merge(beg, mid, end);
}
