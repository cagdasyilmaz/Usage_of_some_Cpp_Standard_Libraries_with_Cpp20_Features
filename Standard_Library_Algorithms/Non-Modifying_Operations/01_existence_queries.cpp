#include <iostream>
#include <vector>

int check_condition = 1;

int main()
{
    std::cout << std::boolalpha;

    std::vector<int> v1 {0,2,9,1,3,8,5,2,9};

    auto const check = [](int x) {return x >= check_condition; };

    std::cout << "Check the number is >= " << check_condition
        << " in vector v1 = {0,2,9,1,3,8,5,2,9} range from 'begin(v1)+1' to 'begin(v1)+8'"  << '\n';
    // in subrange
    std::cout << "all_of: " << all_of (begin(v1)+1, begin(v1)+7, check) << '\n';  // true
    std::cout << "any_of: " << any_of (begin(v1)+1, begin(v1)+7, check) << '\n';  // true
    std::cout << "none_of: " << none_of(begin(v1)+1, begin(v1)+7, check) << '\n';  // false

    std::cout << "Check the number is >= " << check_condition
              << " in entire vector v1 = {0,2,9,1,3,8,5,2,9}"  << '\n';
    // in entire vector:
    std::cout << "all_of: " << all_of (begin(v1), end(v1), check) << '\n';  // false
    std::cout << "any_of: " << any_of (begin(v1), end(v1), check) << '\n';  // true
    std::cout << "none_of: " << none_of(begin(v1), end(v1), check) << '\n';  // false

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::vector<int> v2 {5,2,9,1,3,2,5,2,2,9};
    int check_number = 2;
    std::cout << "Count the number "<< check_number << " in vector v2 = {5,2,9,1,3,2,5,2,2,9}"
                << " range from 'begin(v1)+1' to 'begin(v1)+8'" << '\n';
    // count in subrange
    auto n1 = count(begin(v2)+1, begin(v2)+8, 2);  // n = 3
    std::cout << "n1: " << n1 << '\n';

    std::cout << "Count in entire vector v2 = {5,2,9,1,3,2,5,2,2,9}" << '\n';
    // count in entire vector:
    auto m1 = count(begin(v2), end(v2), 2);  // m = 4
    std::cout << "m1: " << m1 << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';
    std::vector<int> v3 {5,4,9,1,3,2,5,6,8,9};

    std::cout << "Count the even numbers in vector v3 = {5,4,9,1,3,2,5,6,8,9}"
              << " range from 'begin(v1)+1' to 'begin(v1)+8'" << '\n';
    auto const is_even = [](int x) {   return !(x & 1); };
    // count in subrange
    auto n2 = count_if (begin(v3)+1, begin(v3)+8, is_even);  // n = 3
    std::cout << "n2: " << n2 << '\n';

    // count in entire vector:
    std::cout << "Count the even numbers in entire vector v3 = {5,4,9,1,3,2,5,6,8,9}" << '\n';
    auto m2 = count_if (begin(v3), end(v3), is_even);  // m = 4
    std::cout << "m2: " << m2 << '\n';

    return 0;
}
