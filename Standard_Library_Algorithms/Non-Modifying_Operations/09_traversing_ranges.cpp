//
// Created by cagdas on 4.02.2022.
//

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v {1,2,3,4,5,6,7,8};

    std::cout << "read-only, type cheap to copy or copy: \n"
         << "Print the entire vector v={1,2,3,4,5,6,7,8} from begin(v) to end(v) via for_each STL function: ";
    for_each(begin(v), end(v),       [](int x){ std::cout << x << ' '; });
    std::cout << "\nPrint the vector v={1,2,3,4,5,6,7,8} from begin(v)+2 to begin(v)+5 via for_each STL function: ";
    for_each(begin(v)+2, begin(v)+5, [](auto x){ std::cout << x << ' '; });

    std::cout << "\n\nread-only, type expensive to copy: \n"
            << "Print the entire vector v={1,2,3,4,5,6,7,8} via for_each STL function: ";
    for_each(begin(v), end(v), [](int const &x){ std::cout << x << ' '; });
    std::cout << "\nPrint read only the entire vector v={1,2,3,4,5,6,7,8} via for_each STL function: ";
    for_each(begin(v), end(v), [](auto const &x){ std::cout << x << ' '; });


    std::cout << "\n\nmodify the values: \n";
    for_each(begin(v), begin(v)+2, [](int &x){ std::cin >> x; });
    for_each(begin(v), end(v), [](auto &x){ std::cin >> x; });

    std::cout << "read-only, type cheap to copy or copy: \n"
              << "Print the entire vector v={1,2,3,4,5,6,7,8} from begin(v) to end(v) via for_each STL function: ";
    for_each(begin(v), end(v),       [](int x){ std::cout << x << ' '; });
    std::cout << "\nPrint the vector v={1,2,3,4,5,6,7,8} from begin(v)+2 to begin(v)+5 via for_each STL function: ";
    for_each(begin(v)+2, begin(v)+5, [](auto x){ std::cout << x << ' '; });

    std::cout << "\n-----------------------------------------------------------------------------" << '\n';

    v = {1,2,3,4,5,6};
    std::cout << "vector v= {1,2,3,4,5,6} is under operation of next function:\n";

    auto i = next(v.begin());
    std::cout << "after i = next(v.begin()) operation, *i: " << *i << " at distance: " << distance(begin(v), i);

    auto j = next(i, 3);
    std::cout << "\nafter j = next(i, 3) operation, *j: " << *j << " at distance: " << distance(begin(v), j);

    std::cout << "\n-----------------------------------------------------------------------------" << '\n';

    v = {1,2,3,4,5,6};
    std::cout << "vector v= {1,2,3,4,5,6} is under operation of previous function:\n";

    i = prev(v.end());
    std::cout << "after i = prev(v.end()) operation, *i: " << *i << " at distance: " << distance(begin(v), i);

    j = prev(i, 3);
    std::cout << "\nafter j = prev(i, 3) operation, *j: " << *j << " at distance: " << distance(begin(v), j);

    std::cout << "\n-----------------------------------------------------------------------------" << '\n';

    v = {1,2,3,4,5,6};
    std::cout << "vector v= {1,2,3,4,5,6} is under operation of advance function:\n";

    i = v.begin() + 1;
    advance(i, 3);
    std::cout << "after advance(i, 3) operation, *i: " << *i << " at distance: " << distance(begin(v), i);

    return 0;
}