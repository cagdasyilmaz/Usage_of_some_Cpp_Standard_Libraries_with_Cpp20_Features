//
// Created by cagdas on 2.02.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> v {2,3,4,5,6,1,0};

    // test subrange :
    std::cout << "Check (via std::ranges) the vector v={2,3,4,5,6,1,0} range from : begin(v) to begin(v)+5 is sorted or not: ";
    std::cout << std::ranges::is_sorted(begin(v), begin(v)+5);  // true
    std::cout << '\n';

    // test entire vector:
    std::cout << "Check (via std::ranges) the entire vector v={2,3,4,5,6,1,0} is sorted or not: ";
    std::cout << std::ranges::is_sorted(v);  // false
    std::cout << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v =  {2,3,4,5,4,2,0,7,8};

    // test from 1st to 7th :
    std::cout << "Find (via std::ranges) the iterator until the entire vector v={2,3,4,5,4,2,0,7,8} is sorted: \n";
    auto i = std::ranges::is_sorted_until(v);
    // print sorted subrange
    std::cout << "Sorted subrange is: ";
    auto const print = [](int x){ std::cout << x << ' '; };
    std::for_each(begin(v), i, print);  // 2 3 4 5
    std::cout << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    v = {3,7,5,6,4,8,0};

    std::cout << "Find (via std::ranges) the vector v={3,7,5,6,4,8,0} is partitioned (with odd numbers) or not range from : begin(v) to end(v): ";
    auto const is_odd = [](int x) {   return (x & 1); };
    std::cout << std::ranges::is_partitioned(v, is_odd) << '\n';  // true

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::cout << "Find (via std::ranges) partition point of the vector v={3,7,5,6,4,8,0}  (with odd numbers) or not range from : begin(v) to end(v):\n";
    i = std::ranges::partition_point(v, is_odd);
    std::cout << "The partion point is: " << *i << '\n';

    // print 1st subrange
    std::cout << "The first subrange is: ";
    std::for_each(begin(v), i, print);  // 3 7 5
    std::cout << '\n';

    // print 2nd subrange
    std::cout << "The second subrange is: ";
    std::for_each(i, end(v), print);  // 6 4 8 0
    std::cout << '\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::vector<int> v1 {1,2,3,4};
    std::vector<int> v2 {4,2,1,3};
    std::vector<int> v3 {5,0,1,2};

    std::cout << "Is v2={4,2,1,3} is a permutation (via std::ranges) of v1={1,2,3,4} ?: " <<
            std::ranges::is_permutation(v1, v2) << '\n';  // true

    std::cout << "Is v3={5,0,1,2} is a permutation (via std::ranges) of v1={1,2,3,4} ?: " <<
              std::ranges::is_permutation(v1, v3) << '\n';  // false

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    // max heap:
    std::vector<int> h {9,7,8,6,2,1,4};
    std::cout << "Check (via std::ranges) the vector h={9,7,8,6,2,1,4} is a maximum heap or not: " <<
              std::ranges::is_heap(h) << '\n';  // true

    // not a max heap:
    v = {1,2,3,4,5};
    std::cout << "Check (via std::ranges) the vector v={1,2,3,4,5} is a maximum heap or not: " <<
              std::ranges::is_heap(v) << '\n';  // false

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    h = {9,7,8,6,8,1,4};
    auto e = std::ranges::is_heap_until(h);
    if (e == end(h)) {
        std::cout << "The vector h={9,7,8,6,8,1,4} is a complete heap!\n";
    }
    else {
        auto const idx = std::ranges::distance(begin(h), e);  // 4
        std::cout << "The h={9,7,8,6,8,1,4} at h(" << idx << "): " << *e
                  << " does not makes this vector maximum heap."<< '\n';  // 8
        std::cout << "The vector h={9,7,8,6,8,1,4} is a heap until index " << idx << '\n';
        // add one more element to heap
        push_heap(begin(h), next(e));
    }
    return 0;
}