#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{

    Parabola P = Parabola(2, -4, 5);
    Fraction* o = P.GetCoord(P.GetAoS());
    cout << o[0].out() << ", " << o[1].out() << endl;
    cout << P.out() << endl;
    return 0;
}
