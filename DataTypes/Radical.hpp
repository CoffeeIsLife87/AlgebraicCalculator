#include "Fraction.hpp"
#include "Primes.hpp"

class Radical
{
public:
    Radical(int Coef, int Radicand);

    const Fraction GetCoef();
    const int      GetRadicand();

    void Simplify();
    const char* out();

private:
    int Coef;
    int Radicand;

};

Radical::Radical(int Coef = 1, int Radicand = 1)
{
    this->Coef = Coef;
    this->Radicand = Radicand;
}

void Radical::Simplify()
{
    // Gonna need this for factoring
    int* PrimeCounts = NumberOfPrimes(GetPrimes(this->Radicand));

    int NewCoef = 1; // The number left of the radical
    int NewRad = 1;  // The number under the radical

    for (int P = 0; P < PLSize; P++)
    {
        if (PrimeCounts[P] < 1)
        {
            // Don't do anything if the number is 0
            continue;
        }

        if ((PrimeCounts[P] % 2) != 0)
        {
            // Give the 1 to the radicand
            PrimeCounts[P] -= 1;
            NewRad *= PrimeList[P];
        }

        int AddToCoef = PrimeCounts[P]/2;
        for (int C = 0; C < AddToCoef; C++) // C/Coef
        {
            NewCoef *= PrimeList[P];
        }
    }

    this->Coef = NewCoef;
    this->Radicand = NewRad;

}

const char* Radical::out()
{
	string SOut;
	SOut.append(to_string(Coef));
    if (Radicand > 1)
    {
	    SOut.append("√");
	    SOut.append(to_string(Radicand));
    }

	return SOut.c_str();
}