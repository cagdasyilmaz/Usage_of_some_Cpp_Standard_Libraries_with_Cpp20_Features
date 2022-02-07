//
// Created by cagdas on 30.01.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> s {0,4,6,5,1,4,6,5,8,9};
    std::vector<int> w {1,4,6,5,8,9};

    std::cout << "Find (via std::ranges) the subrange of the vector w = {1,4,6,5,8,9} range from 'begin(w)+1' to 'begin(w)+4'" <<
              " in the subrange of  vector s = {0,4,6,5,1,4,6,5,8,9} range from 'begin(s)+1' to 'begin(s)+9'" <<'\n';
    // find subrange of 'w' in subrange of 's'
    auto i = std::ranges::search(begin(s)+1, begin(s)+9, begin(w)+1, begin(w)+4);
    // i != end-of-range
    if (!empty(i)) {  // true => found
        auto const value = i[0];     // int value = 4
        auto const index = std::ranges::distance(begin(s), begin(i));  // index = 1
        std::cout << "values: ";
        for (int x : i) { std::cout << x << ' '; }  // 4 6 5
        std::cout << '\n';
        std::cout << "first index: " << index << '\n';
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "Find (via std::ranges) the entire vector w = {1,4,6,5,8,9} in entire vector s = {0,4,6,5,1,4,6,5,8,9} " << '\n';
    // find all of 'w' in all of 's':
    auto j = std::ranges::search(s, w);
    if (!(empty(j))) {   // true => found
        auto const value = j[0];  // int value = 1
        auto const index = std::ranges::distance(begin(s), begin(j));  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::cout << "Find (via std::ranges) the last occurrence subrange of the vector w = {1,4,6,5,8,9} range from 'begin(w)+1' to 'begin(w)+4'" <<
              " in the subrange of  vector s = {0,4,6,5,1,4,6,5,8,9} range from 'begin(s)+1' to 'begin(s)+9'" <<'\n';
    // find subrange of 'w' in subrange of 's':
    i = std::ranges::find_end(begin(s)+1, begin(s)+9, begin(w)+1, begin(w)+4);
    // i != end-of-range
    if (!empty(i)) {  // true => found
        auto const index = std::ranges::distance(begin(s), begin(i));  // index = 5
        std::cout << "values: " ;
        for(int x : i) { std::cout << x << ' ';}
        std::cout << '\n';
        std::cout << "index: " << index << '\n';
        std::cout << "-----------------------\n";
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "Find (via std::ranges) the last occurrence entire vector w = {1,4,6,5,8,9} in entire vector s = {0,4,6,5,1,4,6,5,8,9} " << '\n';
    // find all of 'w' in all of 's':
    j = std::ranges::find_end(s, w);
    if (!empty(j)) {   // true => found
        auto const index = std::ranges::distance(begin(s), begin(j));  // index = 5
        std::cout << "values: " ;
        for(int x : j) { std::cout << x << ' ';}
        std::cout << '\n';
        std::cout << "index: " << index << '\n';
        std::cout << "-----------------------\n";
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    return 0;
}
