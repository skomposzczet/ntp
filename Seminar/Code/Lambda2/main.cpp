#include <iostream>
#include <functional>

int g(int x, int (*f)(int))
{
    return 2*f(x);
}

int gf(int x, std::function< int(int) > f)
{
    return 2*f(x);
}

struct PrintInt
{
    void operator()(int x)
    {
        std::cout << x << std::endl;
    }
};

int main()
{

    

    std::cout << g(2, [](int x){return 2*x;}) << std::endl;

    /*
    8
    */

    // std::cout << g(2, [](int x){return 2.*x;}) << std::endl; // in lambda: double instead of int, error!!

    /*
    wont compile
    */

    std::cout << g(2, [](int x) -> int {return 2.*x;}) << std::endl;

    /*
    8
    */

    int y = 50;
    // std::cout << g(2, [&](double x){return y*x;}) << std::endl; // error!!

    /*
    wont compile
    */

    // int y = 50;
    std::cout << gf(2, [&](double x){return y*x;}) << std::endl;

    /*
    200
    */

    PrintInt printInt;
    std::function<void(int)> print_int = printInt;
    print_int(7);

    /*
    7
    */
}