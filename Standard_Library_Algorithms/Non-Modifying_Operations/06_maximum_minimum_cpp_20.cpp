//
// Created by cagdas on 1.02.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> v {7,9,3,5,3,2,4,1,8,0};
    // smallest in subrange :
    std::cout << "Find the smallest (via std::ranges) element in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+7";
    auto i = std::ranges::min_element(begin(v)+2, begin(v)+7);
    auto min = *i;  // int min = 2
    std::cout << "\nmin: " << min << '\n';

    // smallest in entire vector:
    std::cout << "Find the smallest element (via std::ranges) in the entire vector v={7,9,3,5,3,2,4,1,8,0} \n";
    auto j = std::ranges::min_element(v);
    std::cout << *j << '\n';  // prints '0'
    // index of smallest:
    auto argmin = std::ranges::distance(begin(v), j);  // int argmin = 9
    std::cout << "argmin: " << argmin << '\n';

    // erase at i's pos:  7935324180
    std::cout << "Erase the position of the i's position:\n*i now shows: ";
    i = v.erase(i);    //
    std::cout << *i << '\n';   // 793534180
    // prints '4'

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v =  {7,9,3,5,3,2,4,1,8,0}; // redefine v vector

    // largest in subrange :
    std::cout << "Find the largest element (via std::ranges) in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+7";
    i = std::ranges::max_element(begin(v)+2, begin(v)+7);
    auto max = *i;  // int max = 5
    std::cout << "\nmax: " << max << '\n';

    // largest in entire vector:
    std::cout << "Find the largest element (via std::ranges) in the entire vector v={7,9,3,5,3,2,4,1,8,0} \n";
    j = std::ranges::max_element(v);
    std::cout << *j << '\n';  // prints '9'

    // index of largest:
    auto argmax = std::ranges::distance(begin(v), j);  // int argmax = 1
    std::cout << "argmax: " << argmax << '\n';

    // erase at i's pos:  7935324180
    std::cout << "Erase the position of the i's position:\n*i now shows: ";
    i = v.erase(i);    //
    std::cout << *i << '\n';   // 793324180
    // prints '3'

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v =  {7,1,3,5,3,8,6,2,9,0};

    std::cout << "Find the smallest and largest element (via std::ranges) in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+8\n";
    // min & max in subrange:
    auto [p1, p2] = std::ranges::minmax_element(begin(v)+2, begin(v)+8);
    min = *p1;    // int min = 2
    max = *p2;   // int max = 8
    std::cout << "min: " << min << ", max: " << max << '\n';

    // swap element values
    std::swap(*p1,*p2); // => 7135386290
    std::cout << "Swap the pair elements: \nFirst after swapped: " <<*p1 << ", \nSecond after swapped: "<< *p2 << '\n';

    // min & max in entire vector:
    std::cout << "Find the smallest and largest element in the entire vector v={7,9,3,5,3,2,4,1,8,0}\n";
    auto [pv1, pv2] = std::ranges::minmax_element(v);
    auto minv = *pv1;    // int minv = 0
    auto maxv = *pv2;   // int maxv = 9
    std::cout << minv <<' '<< maxv << '\n';

    std::cout << "Find the smallest and largest element (via std::ranges) (with C++20 feature) in the entire vector v={7,9,3,5,3,2,4,1,8,0}\n";
    auto [k, l] = std::ranges::minmax_element(v);  // C++20
    std::cout << *k <<' '<< *l << '\n';  // 0 9

    return 0;
}