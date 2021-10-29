#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    //Parabola P = Parabola::ParabolaHK(-2,-3,5);
    Parabola P = Parabola::ParabolaABC(-5,30,0);
    //Parabola P = Parabola::ParabolaPQ();
    cout << P.out() << endl;
    return 0;
}
