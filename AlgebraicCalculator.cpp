#include <iostream>
using namespace std;

#include "Parabola.hpp"


int main()
{
    //VarExpo VE1;
    //VE1.Expo = 1;
    //VE1.VarLetter = *"x";
    //vector<VarExpo> S;
    //S.push_back(VE1);
//
    //Term(Fraction(1), S);
    Parabola P = Parabola(4,24,9);
    cout << P.GetDescriminate().out() << endl;
    return 0;
}
