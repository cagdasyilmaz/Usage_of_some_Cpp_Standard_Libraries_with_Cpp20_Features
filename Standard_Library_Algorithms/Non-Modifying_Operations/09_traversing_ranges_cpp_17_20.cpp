//
// Created by cagdas on 4.02.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> v {1,2,3,4,5,6,7,8};

    std::cout << "read-only, type cheap to copy or copy (via std::ranges): \n"
              << "Print the entire vector v={1,2,3,4,5,6,7,8} from begin(v) to end(v) via for_each STL function: ";
    std::ranges::for_each(v,       [](int x){ std::cout << x << ' '; });
    std::cout << "\nPrint the vector v={1,2,3,4,5,6,7,8} from begin(v)+2 to begin(v)+5 via for_each STL function: ";
    std::ranges::for_each(begin(v)+2, begin(v)+5, [](auto x){ std::cout << x << ' '; });

    std::cout << "\n\nread-only, type expensive to copy (via std::ranges): \n"
              << "Print the entire vector v={1,2,3,4,5,6,7,8} via for_each STL function: ";
    std::ranges::for_each(v, [](int const &x){ std::cout << x << ' '; });
    std::cout << "\nPrint read only the entire vector v={1,2,3,4,5,6,7,8} via for_each STL function: ";
    std::ranges::for_each(v, [](auto const &x){ std::cout << x << ' '; });


    std::cout << "\n\nmodify the values (via std::ranges): \n";
    std::ranges::for_each(begin(v), begin(v)+2, [](int &x){ std::cin >> x; });
    std::ranges::for_each(v, [](auto &x){ std::cin >> x; });

    std::cout << "read-only, type cheap to copy or copy (via std::ranges): \n"
              << "Print the entire vector v={1,2,3,4,5,6,7,8} from begin(v) to end(v) via for_each STL function: ";
    std::ranges::for_each(v,       [](int x){ std::cout << x << ' '; });
    std::cout << "\nPrint the vector v={1,2,3,4,5,6,7,8} from begin(v)+2 to begin(v)+5 via for_each STL function: ";
    std::ranges::for_each(begin(v)+2, begin(v)+5, [](auto x){ std::cout << x << ' '; });

    std::cout << "\n-----------------------------------------------------------------------------" << '\n';

    auto const n = v.size() / 2;

    std::cout << "read-only, type cheap to copy or copy: \n"
              << "Print the vector v begin(v) to begin(v)+(v.size()/2) via for_each_n STL function: ";
    for_each_n(begin(v), n, [](int x){ std::cout << x << ' '; });

    std::cout << "\n\nread-only, type expensive to copy: \n"
              << "Print the vector v from begin(v) to begin(v)+(v.size()/2) via for_each_n STL function: ";
    for_each_n(begin(v), n, [](int const &x){ std::cout << x << ' '; });


    std::cout << "\n\nmodify the values via for_each_n STL function: \n";
    for_each_n(begin(v), n, [](int &x){ std::cin >> x; });

    std::cout << "read-only, type cheap to copy or copy: \n"
              << "Print the vector v from begin(v) to begin(v)+(v.size()/2) via for_each_n STL function: ";
    for_each_n(begin(v), n, [](int x){ std::cout << x << ' '; });

    return 0;
}

