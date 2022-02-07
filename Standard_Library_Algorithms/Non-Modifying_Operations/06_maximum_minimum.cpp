//
// Created by cagdas on 1.02.2022.
//

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v {7,9,3,5,3,2,4,1,8,0};
    // smallest in subrange :
    std::cout << "Find the smallest element in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+7";
    auto i = min_element(begin(v)+2, begin(v)+7);
    auto min = *i;  // int min = 2
    std::cout << "\nmin: " << min << '\n';

    // smallest in entire vector:
    std::cout << "Find the smallest element in the entire vector v={7,9,3,5,3,2,4,1,8,0} \n";
    auto j = min_element(begin(v), end(v));
    std::cout << *j << '\n';  // prints '0'
    // index of smallest:
    auto argmin = distance(begin(v), j);  // int argmin = 9
    std::cout << "argmin: " << argmin << '\n';

    // erase at i's pos:  7935324180
    std::cout << "Erase the position of the i's position:\n*i now shows: ";
    i = v.erase(i);    //
    std::cout << *i << '\n';   // 793534180
    // prints '4'

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v =  {7,9,3,5,3,2,4,1,8,0}; // redefine v vector

    // largest in subrange :
    std::cout << "Find the largest element in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+7";
    i = max_element(begin(v)+2, begin(v)+7);
    auto max = *i;  // int max = 5
    std::cout << "\nmax: " << max << '\n';

    // largest in entire vector:
    std::cout << "Find the largest element in the entire vector v={7,9,3,5,3,2,4,1,8,0} \n";
    j = max_element(begin(v), end(v));
    std::cout << *j << '\n';  // prints '9'

    // index of largest:
    auto argmax = distance(begin(v), j);  // int argmax = 1
    std::cout << "argmax: " << argmax << '\n';

    // erase at i's pos:  7935324180
    std::cout << "Erase the position of the i's position:\n*i now shows: ";
    i = v.erase(i);    //
    std::cout << *i << '\n';   // 793324180
    // prints '3'(via std::ranges)

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v =  {7,1,3,5,3,8,6,2,9,0};

    std::cout << "Find the smallest and largest element in the vector v={7,9,3,5,3,2,4,1,8,0} range from : begin(v)+2 to begin(v)+8\n";
    // min & max in subrange:
    auto p = minmax_element(begin(v)+2, begin(v)+8);
    min = *p.first;    // int min = 2
    max = *p.second;   // int max = 8
    std::cout << "min: " << min << ", max: " << max << '\n';

    // swap element values
    std::swap(*p.first,*p.second); // => 7135386290
    std::cout << "Swap the pair elements: \nFirst after swapped: " <<*p.first << ", \nSecond after swapped: "<< *p.second << '\n';

    // min & max in entire vector:
    std::cout << "Find the smallest and largest element in the entire vector v={7,9,3,5,3,2,4,1,8,0}\n";
    auto pv = minmax_element(begin(v), end(v));
    auto minv = *pv.first;    // int minv = 0
    auto maxv = *pv.second;   // int maxv = 9
    std::cout << minv <<' '<< maxv << '\n';

    std::cout << "Find the smallest and largest element (with C++17 feature) in the entire vector v={7,9,3,5,3,2,4,1,8,0}\n";
    auto [k, l] = minmax_element(begin(v), end(v));  // C++17
    std::cout << *k <<' '<< *l << '\n';  // 0 9

    return 0;
}