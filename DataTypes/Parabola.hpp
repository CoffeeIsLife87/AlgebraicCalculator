//#include "./Terms/Term.h"
#include "Fraction.hpp"

class Parabola
{
public:
    //Term GetX();
    Parabola(Fraction A, Fraction B, Fraction C);
    Fraction GetDescriminate();

private:
    //Term X;
    Fraction A;
    Fraction B;
    Fraction C;
};

Parabola::Parabola(Fraction A, Fraction B, Fraction C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

Fraction Parabola::GetDescriminate()
{
    Fraction V1 = (B * B);
    Fraction V2 = Fraction(4) * A;
    V2 = V2 * C;
    return V1 - V2;
}

//Fraction*