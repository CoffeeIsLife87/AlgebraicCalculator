#include <iostream>
using namespace std;

#include "Parabola.hpp"

int main()
{
    Parabola P = Parabola::ParabolaPQ(1,-3,5); //Parabola::ParabolaHK(-3,2,5);
    cout << P.out() << endl;
    return 0;
}
