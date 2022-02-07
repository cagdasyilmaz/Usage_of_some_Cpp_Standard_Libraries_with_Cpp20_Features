//
// Created by cagdas on 2.02.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> v {1,2,3,4,5,6,7,8};

    // search in subrange:
    std::cout << "binary_search (via std::ranges) of the vector v={1,2,3,4,5,6,7,8} range from: begin(v)+2 to begin(v)+7 for value 4: ";
    std::cout << std::ranges::binary_search(begin(v)+2, begin(v)+7, 4) << '\n';  // true
    // search in entire vector:
    std::cout << "binary_search (via std::ranges) of the entire vector v={1,2,3,4,5,6,7,8} for value 8: ";
    std::cout << std::ranges::binary_search(v, 8) << '\n';  // true
    std::cout << "binary_search (via std::ranges) of the entire vector v={1,2,3,4,5,6,7,8} for value 9: ";
    std::cout << std::ranges::binary_search(v, 9) << '\n';  // false

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v = {0,1,2,3,4,5,6,7,8};

    // find in subrange:
    std::cout << "lower_bound (via std::ranges) of the vector v={0,1,2,3,4,5,6,7,8} range from: begin(v)+3 to begin(v)+7 for value 5: ";
    auto i = std::ranges::lower_bound(begin(v)+3, begin(v)+7, 5);
    if (i != end(v)) {  // true => found
        std::cout << *i << '\n';  // 5
    }

    // find in entire vector
    std::cout << "lower_bound (via std::ranges) of the entire vector v={0,1,2,3,4,5,6,7,8} for value 2: ";
    auto j = std::ranges::lower_bound(v, 2);
    if (j != end(v)) {  // true => found
        std::cout << *j << '\n';  // 2
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    // find in subrange:
    std::cout << "upper_bound (via std::ranges) of the vector v={0,1,2,3,4,5,6,7,8} range from: begin(v)+3 to begin(v)+7 for value 5: ";
    i = std::ranges::upper_bound(begin(v)+3, begin(v)+7, 5);
    if (i != end(v)) {  // true => found
        std::cout << *i << '\n';  // 6
    }

    // find in entire vector
    std::cout << "upper_bound (via std::ranges) of the entire vector v={0,1,2,3,4,5,6,7,8} for value 2: ";
    j = std::ranges::upper_bound(v, 2);
    if (j != end(v)) {  // true => found
        std::cout << *j << '\n';  // 3
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v = {1,1,2,3,4,5,5,5,6,6,7,7,8};

    // find in subrange :
    std::cout << "equal_range (std::ranges) of the entire vector v={1,1,2,3,4,5,5,5,6,6,7,7,8} for value 5: \n";
    auto [r5b, r5e]  = std::ranges::equal_range(v, 5);
    // erase range of '5'
    std::cout << "Beginning position: " << std::ranges::distance(begin(v), r5b) << '\n';
    std::cout << "End position: " << std::ranges::distance(begin(v), r5e) << '\n';
    std::cout << "Erase the equal_range 5s from the vector between v(" << std::ranges::distance(begin(v), r5b)
              << ", " << std::ranges::distance(begin(v), r5e) << "): ";
    v.erase(r5b, r5e);
    for (int x : v) { std::cout << x << ' '; }  // 1 1 2 3 4 6 6 7 7 8
    std::cout << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::vector<int> r1 {0,1,2,3,4,5,6,7};
    std::vector<int> r2 {1,2,3,4,5,6,7};

    std::cout << "Does vector r1={0,1,2,3,4,5,6,7} range from: begin(r1) to end(r2) includes (std::ranges) the vector" <<
              "r2={1,2,3,4,5,6,7} range from: begin(r2)+1 to begin(r2)+5 ?: ";
    std::cout << std::ranges::includes(begin(r1), end(r1), begin(r2)+1, begin(r2)+5) << '\n';  // true

    std::cout << "Does the entire vector r1={0,1,2,3,4,5,6,7} includes (std::ranges) the entire  vector r2={1,2,3,4,5,6,7} ?: ";
    // entire r2 in r1
    std::cout << std::ranges::includes(r1, r2) << '\n';  // true


    return 0;
}