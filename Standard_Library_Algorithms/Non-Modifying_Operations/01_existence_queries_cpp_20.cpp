//
// Created by cagdas on 30.01.2022.
//

#include <iostream>
#include <vector>
#include <algorithm>

int check_condition = 1;

int main()
{
    std::cout << std::boolalpha;

    std::vector<int> v1 {0,2,9,1,3,8,5,2,9};

    auto const check = [](int x) {return x >= check_condition; };

    std::cout << "Check the number (via std::ranges) is >= " << check_condition
              << " in vector v1 = {0,2,9,1,3,8,5,2,9} range from 'begin(v1)+1' to 'begin(v1)+8'"  << '\n';
    // in subrange
    std::cout << "all_of: " << std::ranges::all_of (begin(v1)+1, begin(v1)+7, check) << '\n';  // true
    std::cout << "any_of: " << std::ranges::any_of (begin(v1)+1, begin(v1)+7, check) << '\n';  // true
    std::cout << "none_of: " << std::ranges::none_of(begin(v1)+1, begin(v1)+7, check) << '\n';  // false

    std::cout << "Check the number (via std::range) is >= " << check_condition
              << " in entire vector v1 = {0,2,9,1,3,8,5,2,9}"  << '\n';
    // in entire vector:
    std::cout << "all_of: " << std::ranges::all_of (v1, check) << '\n';  // false
    std::cout << "any_of: " << std::ranges::any_of (v1, check) << '\n';  // true
    std::cout << "none_of: " << std::ranges::none_of(v1,check) << '\n';  // false

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::vector<int> v2 {5,2,9,1,3,2,5,2,2,9};
    int check_number = 2;
    std::cout << "Count (via std::ranges) the number "<< check_number << " in vector v2 = {5,2,9,1,3,2,5,2,2,9}"
              << " range from 'begin(v1)+1' to 'begin(v1)+8'" << '\n';
    // count in subrange
    auto n = std::ranges::count(begin(v2)+1, begin(v2)+8, 2);  // n = 3
    std::cout << "n: " << n << '\n';

    std::cout << "Count (via std::ranges) in entire vector v2 = {5,2,9,1,3,2,5,2,2,9}" << '\n';
    // count in entire vector:
    auto m = std::ranges::count(v2, 2);  // m = 4
    std::cout << "m: " << m << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::cout << "Count how many 3 in vector v2: " << std::ranges::count(v2, 3) << '\n';  // 1
    std::cout << "Count how many 2 in vector v2: " << std::ranges::count(v2, 2) << '\n';  // 3
    std::cout << "Count how many 7 in vector v2: " << std::ranges::count(v2, 7) << '\n';  // 0

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::vector<int> v3 {5,4,9,1,3,2,5,6,8,9};

    std::cout << "Count (via std::ranges) the even numbers in vector v3 = {5,4,9,1,3,2,5,6,8,9}"
              << " range from 'begin(v1)+1' to 'begin(v1)+8'" << '\n';
    auto const is_even = [](int x) {   return !(x & 1); };
    // count in subrange
    auto n2 = std::ranges::count_if (begin(v3)+1, begin(v3)+8, is_even);  // n = 3
    std::cout << "n2: " << n2 << '\n';

    // count in entire vector:
    std::cout << "Count (via std::ranges) the even numbers in entire vector v3 = {5,4,9,1,3,2,5,6,8,9}" << '\n';
    auto m2 = std::ranges::count_if (v3, is_even);  // m = 4

    std::cout << "m2: " << m2 << '\n';

    return 0;
}
