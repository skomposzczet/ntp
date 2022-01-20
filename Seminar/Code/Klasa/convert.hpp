#pragma once

#include <string>

/// Converts given unsigned to binary or hexadecimal
class Convert
{
public:
    /// ctor sets default type converting to to_bin
    Convert() : _conv{&Convert::to_bin} {}
    ~Convert() {};
    
    
    // switching functions
    
    /// Switches converter to 'to binary' mode
    void bin()
    {
        _conv = &Convert::to_bin;
    }
    /// Switches converter to 'to hexadecimal' mode
    void hex()
    {
        _conv = &Convert::to_hex;
    }
    
    
    /// Overloaded operator() allows us to use object as function
    /// @param num Number to convert
    /// @returns String representing converted number
    std::string operator()(const unsigned num) 
    {
        return (this->*_conv)(num);
    }

private:
    /// Pointer to function that actually does converting
    std::string (Convert::*_conv)(const unsigned); 
    
    // converting functions
    std::string to_bin(const unsigned num)
    {
        std::string str{""};
        for (unsigned temp = num ; temp != 0 ; temp /= 2)
            str.insert(str.begin(), ((temp%2 == 1) ? '1' : '0'));
        return str;
    }
    
    std::string to_hex(const unsigned num)
    {
        std::string str{""};
        for (unsigned temp = num ; temp != 0 ; temp /= 16)
            str.insert(str.begin(), ((temp%16<10) ? static_cast<char>((temp%16)+48) : static_cast<char>((temp%16)+55)));
        return str;
    }
    
};