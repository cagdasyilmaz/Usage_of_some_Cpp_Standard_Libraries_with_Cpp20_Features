//
// Created by cagdas on 30.01.2022.
//

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> s {0,4,6,5,1,4,6,5,8,9};
    std::vector<int> w {1,4,6,5,8,9};

    std::cout << "Find the subrange of the vector w = {1,4,6,5,8,9} range from 'begin(w)+1' to 'begin(w)+4'" <<
            " in the subrange of  vector s = {0,4,6,5,1,4,6,5,8,9} range from 'begin(s)+1' to 'begin(s)+9'" <<'\n';
    // find subrange of 'w' in subrange of 's'
    auto i = search(begin(s)+1, begin(s)+9, begin(w)+1, begin(w)+4);
    // i != end-of-range
    if (i != begin(s)+9) {  // true => found
        auto const value = *i;     // int value = 4
        auto const index = distance(begin(s), i);  // index = 1
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "Find the entire vector w = {1,4,6,5,8,9} in entire vector s = {0,4,6,5,1,4,6,5,8,9} " << '\n';
    // find all of 'w' in all of 's':
    auto j = search(begin(s), end(s), begin(w), end(w));
    if (j != end(s)) {   // true => found
        auto const value = *j;  // int value = 1
        auto const index = distance(begin(s), j);  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::cout << "Find the last occurrence subrange of the vector w = {1,4,6,5,8,9} range from 'begin(w)+1' to 'begin(w)+4'" <<
              " in the subrange of  vector s = {0,4,6,5,1,4,6,5,8,9} range from 'begin(s)+1' to 'begin(s)+9'" <<'\n';
    // find subrange of 'w' in subrange of 's':
    i = find_end(begin(s)+1, begin(s)+9, begin(w)+1, begin(w)+4);
    // i != end-of-range
    if (i != begin(s)+9) {  // true => found
        auto const value = *i;     // int value = 4
        auto const index = distance(begin(s), i);  // index = 5
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
        std::cout << "-----------------------\n";
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    std::cout << "Find the last occurrence entire vector w = {1,4,6,5,8,9} in entire vector s = {0,4,6,5,1,4,6,5,8,9} " << '\n';
    // find all of 'w' in all of 's':
    j = find_end(begin(s), end(s), begin(w), end(w));
    if (j != end(s)) {   // true => found
        auto const value = *j;  // int value = 1
        auto const index = distance(begin(s), j);  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }
    else
    {
        std::cout << "No subrange is found" << std::endl;
    }

    return 0;
}
