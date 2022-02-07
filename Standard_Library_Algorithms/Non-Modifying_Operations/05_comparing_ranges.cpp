//
// Created by cagdas on 31.01.2022.
//

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> r1 {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> r2 {1,2,3,4,5,6,0,0};

    std::cout << "Comparing subrange of the vector r1 = {0,1,2,3,4,5,6,7,8,9} range from 'begin(r1)+2' to 'begin(r1)+7'" <<
              " with vector r2 = {1,2,3,4,5,6,0,0} range from 'begin(s)+1'" <<'\n';
    // compare subranges:
    std::cout << ": " << equal(begin(r1)+2, begin(r1)+7, begin(r2)+1) << '\n';  // true

    std::cout << "Comparing entire vector r1 = {0,1,2,3,4,5,6,7,8,9} with entire vector r2 = {1,2,3,4,5,6,0,0}" <<'\n';
    // compare entire containers:
    std::cout << ": " << equal(begin(r1), end(r1), begin(r2)) << '\n';  // false

    std::cout << "Comparing subrange of the vector r1 = {0,1,2,3,4,5,6,7,8,9} range from 'begin(r1)+2' to 'begin(r1)+7'" <<
              " with vector r2 = {1,2,3,4,5,6,0,0} range from 'begin(s)+1' to 'begin(s)+6'" <<'\n';
    // compare other subranges:
    std::cout << ": " <<equal(begin(r1)+1, begin(r1)+7,begin(r2), begin(r2)+6) << '\n';  // true
    // custom type

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::cout << "Custom type of container, result: " ;
    struct P {int x; char q;};
    std::vector<P> a {{1,'n'}, {2,'m'}};
    std::vector<P> b {{1,'y'}, {2,'z'}};
    // compare 'P's only by member 'x'
    std::cout << equal(begin(a), end(a), begin(b), end(b),
                       [](P p1, P p2) { return p1.x == p2.x; }) << '\n';// true

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    r1 = {0,1,2,3,4,5,6,7,8,9};
    r2 = {1,2,3,4,5,7,8,8};

    // compare:
    std::cout << "Comparing subrange of the vector r1 = 0,1,2,3,4,5,6,7,8,9} range from 'begin(r1)+2' to 'begin(r1)+9'" <<
              " with vector r2 = {1,2,3,4,5,7,8,8} range from 'begin(s)+1' for mismatch" <<'\n';
    auto p = mismatch(begin(r1)+2, begin(r1)+9, begin(r2)+1);
    // != end-of-range => mismatch
    if (p.first  != begin(r1)+9)
    {
        auto p1value = *p.first;
        std::cout << "p1value: " << p1value << '\n';
    }  // 6
    if (p.second != end(r2))
    { auto p2value = *p.second;
        std::cout << "p2value: " << p2value << '\n';
    }  // 7
    else
    {
        std::cout << "There is not any mismatch in these container ranges." << '\n';
    }

    std::cout << "Comparing entire vector r1 = 0,1,2,3,4,5,6,7,8,9} with entire vector r2 = {1,2,3,4,5,7,8,8} for mismatch" <<'\n';
    // compare entire containers:
    auto q = mismatch(begin(r1), end(r1), begin(r2));
    if (q.first != end(r1)) {
        auto q1value = *q.first;  // 0
        auto q1index = distance(begin(r1), q.first);  // 0
        std::cout << "-----------------------\n";
        std::cout << "q1value: " << q1value << '\n';
        std::cout << "q1index: " << q1index << '\n';
        std::cout << "-----------------------\n";
    }
    else
    {
        std::cout << "There is not any mismatch in this container range." << '\n';
    }

    if (q.second != end(r2)) {
        auto q2value = *q.second;  // 1
        auto q2index = distance(begin(r2), q.second);  // 0
        std::cout << "q2value: " << q2value << '\n';
        std::cout << "q2index: " << q2index << '\n';
    }
    else
    {
        std::cout << "There is not any mismatch in this container range." << '\n';
    }

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::string s1 = "xalgori";
    std::string s2 = "abced";
    // compare subranges
    std::cout << "Comparing subrange of the string s1 = xalgori range from 'begin(s1)+1' to 'begin(s1)+5'" <<
              " with string s2 = abced range from 'begin(s2)+1 to' begin(s2)+4: " << '\n';
    std::cout << lexicographical_compare(begin(s1)+1, begin(s1)+5,begin(s2)+1, begin(s2)+4) << '\n';  // true (r1 before r2)

    // compare entire containers:
    std::cout << "Comparing the entire string s1 = xalgori with string s2 = abced: "<< '\n';
    std::cout << lexicographical_compare(  begin(s1), end(s1),begin(s2), end(s2)) << '\n';  // false (r1 after r2)
    // strings are actually already comparable:
    std::cout << "strings are actually already comparable:" << '\n' << "s1 < s2: " << (s1 < s2) << '\n';  // false
    std::cout << "s1 > s2: " << (s1 > s2) << '\n';  // true (r1 after r2)

    // custom type
    struct Q { int x; int y; };
    std::vector<Q> c { Q{1,9}, Q{2,9} };
    std::vector<Q> d { Q{1,8}, Q{3,8} };
    // compare 'P's only by member 'x'
    std::cout << lexicographical_compare(begin(c),end(c), begin(d),end(d),
                                         [](Q q1, Q q2) { return q1.x < q2.x; } ) << '\n';  // true

    return 0;
}