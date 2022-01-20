// ┌─────────────────────────────────────────────────────────────────────────────────────┐
// │ Napisz klasę Sinus z przeładowanym operatorem (). Ma on przyjmować argument double  │
// │ i zwracać wyliczony sinus. Klasa ma mieć dwa stany, jeden w którym przyjmowany      │
// │ argument będzie w stopniach, a w drugim w radianach. Pomiędzy stanami można         │
// │ się przełączać metodami set_degrees i set_radians. Ustaw liczenie w stopniach       │
// │ jako domyślne.                                                                      │
// └─────────────────────────────────────────────────────────────────────────────────────┘

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │ Wskazówka: gdy x jest w radianach sin liczymy                                │
// │      sin(x)                                                                  │
// │ A gdy w stopniach:                                                           │
// │      sin(x*M_PI/180)                                                         │
// └──────────────────────────────────────────────────────────────────────────────┘


#include <iostream>
#include "sinus.hpp"

int main()
{
    Sinus sinus;
    std::cout << sinus(90) << std::endl;
    std::cout << sinus(77) << std::endl;
    sinus.set_radians();
    std::cout << sinus(M_PI/2) << std::endl;
    std::cout << sinus(M_PI*.8) << std::endl;
    sinus.set_degrees();
    std::cout << sinus(12) << std::endl;
}
/* Oczekiwany output:
1
0.97437
1
0.587785
0.207912
*/
