#pragma once

#include <iostream>
#include <cmath>

class Sinus
{
public:
    Sinus() { convert = &Sinus::to_degrees; }
    enum arg {radian, degree, grad};

    void set_radians()
    {
        convert = &Sinus::to_radians;
    }
    void set_degrees()
    {
        convert = &Sinus::to_degrees;
    }

    double operator() (double x)
    {
        return sin(( this->*convert)(x) );
    }

private:
    double (Sinus:: * convert) (double) ;

    double to_radians(double x) {return x;}
    double to_degrees(double x) {return x*M_PI/180;}


};