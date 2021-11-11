#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main(int argc, char *argv[] )
{
    //Parabola P = Parabola::ParabolaHK(1,-3,-5);
    Parabola P = Parabola::ParabolaABC(1,0,-16);
    //Parabola P = Parabola::ParabolaPQ(5,-3,1);
    cout << P.out() << endl;
    return 0;
}
