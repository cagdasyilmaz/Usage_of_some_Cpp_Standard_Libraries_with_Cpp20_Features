//
// Created by cagdas on 30.01.2022.
//

#include <vector>
#include <iostream>

int main ()
{
    std::vector<int> v1 {5,5,2,8,2,2,3,3,2,8};
    // find in subrange:
    std::cout << "Find the adjacent number in vector v1 = {5,5,2,8,2,2,3,3,2,8}"
        << "range from 'begin(v1)+1' to 'begin(v1)+8'"  << '\n';
    auto i = adjacent_find(begin(v1)+1, begin(v1)+8);
    // i != end-of-range
    if (i != begin(v1)+8)
    {  // true => found
        auto const value = *i;     // int value = 2
        auto const index = distance(begin(v1), i);  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not any adjacent element in this vector range." << '\n';
    }

    // find in entire vector:
    std::cout << "Find the adjacent number in entire vector v1 = {5,5,2,8,2,2,3,3,2,8}" << '\n';
    auto j = adjacent_find(begin(v1), end(v1));
    if (j != end(v1))
    {   // true => found
        auto const value = *j;  // int value = 5
        auto const index = distance(begin(v1), j);  // index = 0
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
    i = search_n(begin(v2)+1, begin(v2)+9, n, 2);
    // i != end-of-range
    if (i != begin(v2)+9) {  // true => found
        auto const value = *i;     // int value = 2
        auto const index = distance(begin(v2), i);  // index = 5
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not such a occurrence." << '\n';
    }

    // find run of 3 9s in entire vector:
    std::cout << "Find the adjacent 9s " << n << " times in entire vector v2 = {0,5,2,2,8,2,2,2,9,9,9}" << '\n';
    j = search_n(begin(v2), end(v2), n, 9);
    if (j != end(v2)) {   // true => found
        auto const value = *j;  // int value = 9
        auto const index = distance(begin(v2), j);  // index = 8
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "There is not such a occurrence." << '\n';
    }

    return 0;
}