#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    Parabola P = Parabola::ParabolaABC(2,-4,5); //Parabola::ParabolaHK(-3,2,5);
    cout << P.out() << endl;
    return 0;
}
