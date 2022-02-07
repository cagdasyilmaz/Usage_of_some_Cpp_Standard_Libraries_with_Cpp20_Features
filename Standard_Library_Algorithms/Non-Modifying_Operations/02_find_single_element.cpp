//
// Created by cagdas on 30.01.2022.
//

#include <iostream>
#include <vector>

int check_condition = 6;

int main ()
{
    std::vector<int> v1 {9,0,4,1,3,8,5,2,9};

    int number1 = 8;
    std::cout << "Find the number " << number1
        << " in vector v1 = {9,0,4,1,3,8,5,2,9} range from 'begin(v1)+2' to 'begin(v1)+ 7'"  << '\n';
    // find '8' in subrange:
    auto i = find(begin(v1)+2, begin(v1)+7, 8);
    // i != end-of-range
    if (i != begin(v1)+7) {
        std::cout << number1 << " found!\n";
    }  // true => found

    number1 = 9;
    std::cout << "Find the number " << number1 << " in entire vector v1 = {9,0,4,1,3,8,5,2,9}"  << '\n';
    // find '9' in entire vector:
    auto j = find(begin(v1), end(v1), number1);
    if (j != end(v1)) {   // true => found
        auto const value = *j;  // int value = 9
        auto const index = distance(begin(v1), j);  // index = 0
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }

    std::cout << "Find the next occurrence number " << number1 << " in entire vector v1 = {9,0,4,1,3,8,5,2,9}"  << '\n';
    // find next occurrence of '9'
    j = find(next(j), end(v1), number1);
    if (j != end(v1)){
        std::cout << number1 << " found!\n";
        auto const index = distance(begin(v1), j);  // index = 0
        std::cout << "index: " << index << '\n';
    }  // true => found

    number1 = 7;
    std::cout << "Find the next occurrence number " << number1 << " in entire vector v1 = {9,0,4,1,3,8,5,2,9}"  << '\n';
    // find '7' in entire vector:
    auto k = find(begin(v1), end(v1), number1); //         k
    if (k != end(v1)){
        std::cout << "7 found!\n";
    }  // false => NOT found
    else{
        std::cout << "7 not found!\n";
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    auto const f = [](int x) {   return x >= check_condition; };
    std::cout << "Find the first number >= " << check_condition
              << " in vector v1 = {9,0,4,1,3,8,5,2,9} range from 'begin(v1)+2' to 'begin(v1)+ 7'"  << '\n';
    // find in subrange
    auto i2 = find_if(begin(v1)+2, begin(v1)+7, f);
    // i != end-of-range
    if (i2 != begin(v1)+7) {  // true => found
        auto const value = *i2;     // int value = 8
        std::cout << "value: " << value << '\n';
    }

    std::cout << "Find the first number >= " << check_condition
              << " in entire vector v1 = {9,0,4,1,3,8,5,2,9}"  << '\n';
    // find in entire vector:
    auto j2 = find_if(begin(v1), end(v1), f);
    if (j2 != end(v1)) {   // true => found
        auto const value = *j2;  // int value = 9
        auto const index = distance(begin(v1), j2);  // index = 0
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::cout << "Find if not the first number >= " << check_condition
              << " in vector v1 = {9,0,4,1,3,8,5,2,9} range from 'begin(v1)+2' to 'begin(v1)+ 7'"  << '\n';
    // find in subrange
    i = find_if_not(begin(v1)+2, begin(v1)+7, f);
    // i != end-of-range
    if (i != begin(v1)+7) {  // true => found
        auto const value = *i;     // int value = 8
        std::cout << "value: " << value << '\n';
    }

    std::cout << "Find if not the first number >= " << check_condition
              << " in entire vector v1 = {9,0,4,1,3,8,5,2,9}"  << '\n';
    // find in entire vector:
    j = find_if_not(begin(v1), end(v1), f);
    if (j != end(v1)) {   // true => found
        auto const value = *j;  // int value = 9
        auto const index = distance(begin(v1), j);  // index = 0
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::vector<int> s {0,1,3,2,5,7,4,8,9,9};
    std::vector<int> w {1,4,6,5,8,7};

    // returns an iterator to the 1st element in range s that compares equal to any of the elements in range w;
    // otherwise returns @send if no such element was found
    // find in subrange of v

    std::cout << "Find in vector s = {0,1,3,2,5,7,4,8,9,9} range from 'begin(s)+1' to 'begin(s)+ 9'"  << '\n'
        << "that compares equal to any of the elements in w = {1,4,6,5,8,7} range from 'begin(w)+1' to 'begin(w)+ 4'"
        << '\n';

    i = find_first_of(begin(s)+1, begin(s)+9, begin(w)+1, begin(w)+4);
    // i != end-of-range
    if (i != begin(s)+9) {  // true => found one
        auto const value = *i;     // int value = 5
        auto const index = distance(begin(s), i);  // index = 4
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
        std::cout << "-----------------------\n";
    }
    std::cout << "Find in vector entire s = {0,1,3,2,5,7,4,8,9,9} "  << '\n'
              << "that compares equal to any of the elements in entire w = {1,4,6,5,8,7} " << '\n';

    // find any of 'w' in all of 's':
    j = find_first_of(begin(s), end(s), begin(w), end(w));
    if (j != end(s)) {   // true => found one
        auto const value = *j;  // int value = 1
        auto const index = distance(begin(s), j);  // index = 1
        std::cout << "value: " << value << '\n';
        std::cout << "index: " << index << '\n';
    }

    return 0;
}