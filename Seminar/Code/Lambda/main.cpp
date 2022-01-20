#include <iostream>
#include <string>
#include <vector> 
#include <numeric> 
#include <algorithm> 

int main()
{
    std::vector<int> foo(10);
    std::vector<int> bar(10);

    std::iota(foo.begin(), foo.end(), 0); // fill foo with 0, 1, 2, ...

    for (auto num : foo)
        std::cout << num << " ";
    std::cout << std::endl;

    // lambda returns every element of foo raised to the power of 2
    std::transform(foo.begin(), foo.end(), bar.begin(), [](int x){return x*x; });

    for (auto num : bar)
        std::cout << num << " ";
    std::cout << std::endl;

    /*
    0 1 2 3 4 5 6 7 8 9 
    0 1 4 9 16 25 36 49 64 81
    */ 


    ///// PRZECHWYTYWANIE NAZW /////

    int x = 10, y = 3;
    std::cout <<[ x, & y ] { return x + y; }() << std::endl;

    /*
    13
    */

    //// ATRYBUTY /////

    // int a = 5;
    // std::cout << [a]{a=10; return a;}(); // error

    /*
    wont compile
    */

    int a = 5;
    std::cout << [a]() mutable {a=10; return a;}() << std::endl; 

    /*
    10
    */

    ///// TYP /////

    auto lam = [](int x){return ++x;};
    x = 0;
    std::cout << lam(x) << std::endl;

    /*
    1
    */

    int i = 0;
    int j = 0;
    auto lambda1 = [i, &j]()mutable
    {
        ++i;
        ++j;
        std::cout << "Inside lambda: \ti = " << i << ", j = " << j << std::endl;
    };
    lambda1();
    lambda1();
    std::cout << "In main: \ti = " << i << ", j = " << j << "\n\n\n";

    /*
    Inside lambda: 	i = 1, j = 1
    Inside lambda: 	i = 2, j = 2
    In main: 	    i = 0, j = 2
    */

    // int i = 0;
    // int j = 0;
    i = j = 0;
    auto lambda2 = [&, i]()mutable
    {
        ++i;
        ++j;
        std::cout << "Inside lambda: \ti = " << i << ", j = " << j << std::endl;
    };
    lambda2();
    i = 5;
    j = 5;
    std::cout << "In main: \ti = " << i << ", j = " << j << std::endl;
    lambda2();
    std::cout << "In main: \ti = " << i << ", j = " << j << "\n\n\n";

    /*
    Inside lambda: 	i = 1, j = 1
    In main: 	    i = 5, j = 5
    Inside lambda: 	i = 2, j = 6
    In main: 	    i = 5, j = 6
    */

    auto lambda3 = [ how_many = 0]() mutable 
    {
        std::cout << "Lambda called: " << ++how_many << " time(s)" << std::endl;
    };
    lambda3();
    lambda3();

    /*
    Lambda called: 1 time(s)
    Lambda called: 2 time(s)
    */

}