#include <iostream>

#include "convert.hpp"

int main()
{
    Convert convert;
    const unsigned num = 51966;
    // dec to bin
    std::cout << "Using default state, decimal to binary.\n\t";
    std::cout << convert(num) <<std::endl;

    // dec to hex
    convert.hex();
    std::cout << "Switching to hex mode.\n\t";
    std::cout << convert(num) <<std::endl;

    // dec to bin
    convert.bin();
    std::cout << "Back to bin mode.\n\t";
    std::cout << convert(num) <<std::endl;

    /*
    Using default state, decimal to binary.
        1100101011111110
    Switching to hex mode.
        CAFE
    Back to bin mode.
        1100101011111110
    */
}