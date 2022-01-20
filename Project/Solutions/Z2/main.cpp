#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>

#include "str.hpp"

int main()
{
    srand(time(NULL));

    std::cout << std::count_if(str.begin(), str.end(), [](char c){return (c >= '0' && c <= '9');}) << std::endl;

    char c = rand()%('z'-'a'+1)+'a';
    std::cout << "ilosc wystapien '" << c << "': "<< std::count_if(str.begin(), str.end(), [c](char ch){return c==ch;}) << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), [](char c){return toupper(c); });
    // std::for_each(str.begin(), str.end(), [](char & c){c = toupper(c);});
    std::ofstream file("str_out");
    if (file.is_open())
    {   
        file << str;
        file.close();
    }
    else
        std::cerr << "wtf" << std::endl;

    std::vector<int> fib(10,0);
    std::generate(fib.begin(), fib.end(), [p = 0, n = 1]()mutable{auto temp = p; p = n; n += temp; return temp; });
    for (auto i : fib)
        std::cout << i << ", ";
    std::cout << "\b\b \n";
}
