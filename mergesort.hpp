#include <iterator>
#include <vector>
#include <iostream>
 /*
template<typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end)
{
    std::vector<typename It::value_type> v;
    It it_l{ begin }, it_r{ mid };
    const It it_mid{ mid }, it_end{ end };

    while (it_l != it_mid && it_r != it_end)
    {
        v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
    }   

    v.insert(v.end(), it_l, it_mid);    
    v.insert(v.end(), it_r, it_end);

    return std::move(v);
}

template<typename IteratorType>
void merge_sort(IteratorType begin, IteratorType end)
{
    auto size = std::distance(begin, end);
    if (size < 2)
        return;

    auto mid = std::next(begin, size / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);

    auto &&v = merge(begin, mid, end);
    std::move(v.cbegin(), v.cend(), begin);
}
*/

template<typename Iter>
void merge(Iter beg, Iter mid, Iter end)
{
    std::vector<typename Iter::value_type> temp;
    temp.reserve(std::distance(beg, end));

   // std::cout << "merge "; print(beg, mid, false); std::cout << "↔ "; print(mid, end);
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
    //std::cout << " ⇒    "; print(beg, end);
}

template<typename Iter>
void merge_sort(Iter beg, Iter end)
{
    //std::cout << "sort  "; print(beg, end);

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