#include <iostream>
#include <vector>
// #include <functional>
#include <algorithm>

int main()
{
    ///// GENERATORY ////

    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), [i = 1]() mutable {return ++i;});
    for (auto n : v)
        std::cout << n << " ";
    std::cout << std::endl;

    /*
    2 3 4 5 6 7 8 9 10 11
    */

    //// PREDYKATY

    std::cout << std::count_if(v.begin(), v.end(), [](int x){return x%2==0;}) << std::endl;

    /*
    5
    */

    //// FUNKTORY PREDEFINIOWANE /////

    std::negate<int> neg; // creating object of predefined negate functor
    std::vector<int> v2(10);
    std::transform(v.begin(), v.end(), v2.begin(), neg); 
    for (auto n : v2)
        std::cout << n << " ";
    std::cout << std::endl;

    /*
    -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 
    */
}