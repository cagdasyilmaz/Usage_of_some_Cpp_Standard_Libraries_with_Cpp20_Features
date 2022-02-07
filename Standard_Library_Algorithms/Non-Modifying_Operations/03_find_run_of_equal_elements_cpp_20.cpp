//
// Created by cagdas on 30.01.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>
int main ()
{
    std::vector<int> v {5,5,2,8,2,2,3,3,2,8};
    // find in subrange:
    std::cout << "Find (via std::ranges) the adjacent number in vector v = {5,5,2,8,2,2,3,3,2,8}"
              << "range from 'begin(v1)+1' to 'begin(v1)+8'"  << '\n';
    auto i = std::ranges::adjacent_find(begin(v)+1, begin(v)+8);
    // i != end-of-range
    if (i != begin(v)+8)
    {  // true => found
        auto const value = *i;     // int value = 2
        auto const index = std::ranges::distance(begin(v), i);  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not any adjacent element in this vector range." << '\n';
    }

    // find in entire vector:
    std::cout << "Find (via std::ranges) the adjacent number in entire vector v = {5,5,2,8,2,2,3,3,2,8}" << '\n';
    auto j = std::ranges::adjacent_find(v);
    if (j != end(v))
    {   // true => found
        auto const value = *j;  // int value = 5
        auto const index = std::ranges::distance(begin(v), j);  // index = 0
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not any adjacent element in this vector." << '\n';
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::vector<int> v2 {0,5,2,2,8,2,2,2,9,9,9};

    // find run of 3 2s in subrange
    const auto n = 3;

    std::cout << "Find the adjacent 2s " << n << " times in vector v2 = {0,5,2,2,8,2,2,2,9,9,9}"
              << "range from 'begin(v2)+1' to 'begin(v2)+9'"  << '\n';
    auto k = std::ranges::search_n(begin(v2)+1, begin(v2)+9, n, 2);
    // i != end-of-range
    if (!empty(k)) {  // true => found
        auto const value = k[0];     // int value = 2
        auto const index = distance(begin(v2), begin(k));  // index = 5
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not such a occurrence." << '\n';
    }


    // find run of 3 9s in entire vector:
    std::cout << "Find the adjacent 9s " << n << " times in entire vector v2 = {0,5,2,2,8,2,2,2,9,9,9}" << '\n';
    auto r = std::ranges::search_n(v2, n, 9);
    if (!empty(r))
    {   // true => found
        auto const value = r[0];  // int value = 9
        auto const index = std::ranges::distance(begin(v2), begin(r));  // index = 8
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not such a occurrence." << '\n';
    }

    return 0;
}
