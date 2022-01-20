// W każdym zadaniu wykorzystaj wyrażenie(a) lambda!

#include <iostream>
#include <algorithm>    // może się przydać!
#include <vector>   
#include <fstream>      // for files
#include <cstdio>       // random 
#include <ctime>        // stuff

#include "str.hpp"

int main()
{
    srand(time(NULL));

    // 1. Policz ilość wystąpień cyfr w stringu str (z pliku str.hpp).
    int dig_count = 0;
    // dig_count = 
    std::cout << "Digit counter: " << dig_count << std::endl;


    /// 2. Policz ilość wystąpień znaku random_char w tym samym stringu
    char random_char = rand()%('z'-'a'+1)+'a';
    int char_count = 0;
    // char_count = 
    std::cout << "Char '" << random_char << "' appeared " << char_count << " times." << std::endl;


    // 3. W stringu str zmień wszystkie wystąpienia małych liter na duże litery.

    // Lepiej go nie wypisywać 
    std::ofstream file("str_upper");
    if (file.is_open())
    {   
        file << str;
        file.close();
    } 


    // 4. Wypełnij vector fib kolejnymi liczbami ciągu fibonacciego (zaczynając od 0)
    std::vector<int> fib(20,0);

    for (auto f : fib)
        std::cout << f << ", ";
    std::cout << "\b\b \n";
}