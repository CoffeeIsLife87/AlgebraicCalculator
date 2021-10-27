#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    Parabola P = Parabola::ParabolaABC(2,6,3); //Parabola::ParabolaHK(-3,2,5);
    cout << P.out() << endl;
    return 0;
}
