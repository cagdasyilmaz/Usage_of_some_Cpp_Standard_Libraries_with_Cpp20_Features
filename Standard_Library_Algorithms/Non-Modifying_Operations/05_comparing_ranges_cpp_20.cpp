//
// Created by cagdas on 31.01.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> range1 {2,3,4,5,6};
    std::vector<int> range2 {2,3,4,5,6};
    std::cout << "Comparing (via std::ranges) entire vector range1 = {2,3,4,5,6} with entire vector ranges2 = {2,3,4,5,6}" <<'\n';
    // compare:
    std::cout << ": " << std::ranges::equal(range1, range2) << '\n';  // true

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::cout << "Custom type of container, result: " ;
    struct P { int x; char q; };
    std::vector<P> a { P{1,'n'}, P{2,'m'} };
    std::vector<P> b { P{1,'y'}, P{2,'z'} };
    // compare 'P's only by member 'x'
    std::cout << std::ranges::equal(a, b,
                       [](P p1, P p2) { return p1.x == p2.x; } ) << '\n';  // true

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    range1 = {1,5,4,6,3};
    range2 = {1,5,4,7,3};

    std::cout << "Comparing (via std::ranges) entire vector range1 = {1,5,4,6,3} with entire vector range2 = {1,5,4,7,3} for mismatch" <<'\n';
    auto [p1, p2] = std::ranges::mismatch(range1, range2);
    auto const value1 = *p1;  // 6
    auto const value2 = *p2;  // 7
    std::cout << "value1: " << value1 << ", distance: " << std::ranges::distance(begin(range1), p1)  <<'\n';
    std::cout << "value2: " << value2 << ", distance: " << std::ranges::distance(begin(range2), p2)  <<'\n';

    std::cout << "-----------------------------------------------------------------------------" << '\n';

    std::string s1 = "xalgori";
    std::string s2 = "abced";
    // compare subranges
    std::cout << "Lexicographical comparing (via std::ranges) subrange of the string s1 = xalgori range from 'begin(s1)+1' to 'begin(s1)+5'" <<
              " with string s2 = abced range from 'begin(s2)+1 to' begin(s2)+4: " << '\n';
    std::cout << std::ranges::lexicographical_compare(begin(s1)+1, begin(s1)+5,begin(s2)+1, begin(s2)+4) << '\n';  // true (r1 before r2)

    // compare entire containers:
    std::cout << "Lexicographical comparing (via std::ranges) the entire string s1 = xalgori with string s2 = abced: "<< '\n';
    std::cout << "using std::less<>{}: " << std::ranges::lexicographical_compare( s1, s2, std::less<>{}) << '\n';
    std::cout << "using std::greater<>{}: "<<std::ranges::lexicographical_compare( s1, s2, std::greater<>{}) << '\n';  // false (r1 after r2)
    // strings are actually already comparable:
    std::cout << "strings are actually already comparable:" << '\n' << "s1 < s2: " << (s1 < s2) << '\n';  // false
    std::cout << "s1 > s2: " << (s1 > s2) << '\n';  // true (r1 after r2)

    // custom type
    struct Q { int x; int y; };
    std::vector<Q> c { Q{1,9}, Q{2,9} };
    std::vector<Q> d { Q{1,8}, Q{3,8} };
    // compare 'P's only by member 'x'
    std::cout << std::ranges::lexicographical_compare(c, d, [](Q q1, Q q2) { return q1.x < q2.x; } ) << '\n';  // true

    return 0;
}