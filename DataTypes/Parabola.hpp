#include <cmath>
#include "Radical.hpp"

class Parabola
{
public:
    //Term GetX();
    Parabola(int A, int B, int C);
    int GetDescriminate();

    Fraction GetAoS();
    Fraction* GetCoord(Fraction X);

    const bool IsRootNumber();
    const Fraction* GetRoots();
    void CalculateRoots();

    string out();

private:
    //Term X;
    int A = 1;
    int B = 1;
    int C = 1;

    bool RootIsNumber = false;
    bool Invert = false;

    Fraction* Roots = new Fraction[3];
    char* WrittenOut;
};

Parabola::Parabola(int A, int B, int C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

Fraction Parabola::GetAoS()
{
    Fraction Ret = Fraction((this->B * -1) , (this->A * 2));
    Ret.SimplifyFraction();
    return Ret;
}

Fraction* Parabola::GetCoord(Fraction X)
{
    Fraction F1;
    F1 = (Fraction)this->A * (X * X);

    Fraction F2;
    F2 =  (Fraction)this->B * X;

    Fraction Y = F1 + F2 + this->C;
    Fraction* Ret = new Fraction[2];
    Ret[0] = X;
    Ret[1] = Y;
    return Ret;
}

int Parabola::GetDescriminate()
{
    int V1 = (B * B);
    int V2 = 4 * A;
    V2 = V2 * C;
    return V1 - V2;
}

const bool Parabola::IsRootNumber()
{
    return RootIsNumber;
}

const Fraction* Parabola::GetRoots()
{
    return Roots;
}

// This will return at most 3 values. The first item is the return count. The second is the left root (or only), the 
void Parabola::CalculateRoots()
{
    // Just assume it's a number. If it's not, we'll specify later
    RootIsNumber = true;

    // Get the current descriminate
    int Descrim = GetDescriminate();
    
    //cout << Descrim << endl;

    // If it's a negative number then return no roots
    if (Descrim < 0)
    {
        Roots[0] = 0;
        RootIsNumber = false;
        return;
    }

    // B needs to be negative here anyways, so this operation happens regardless of root count
    int TempB = B;
    TempB = TempB * -1;

    int TempA = A;
    TempA = TempA * 2;

    // We'll need the square root of the descriminate regardless of root count
    Radical NewD = Radical(1,Descrim);
    NewD.Simplify();

    if (!NewD.IsPerfectSquare())
    {
        Roots[0] = 1;
        std::string WriteOut;
        WriteOut.append(std::to_string((signed int)B));
        WriteOut.append("∓");
        WriteOut.append(NewD.out());
        int Underscorecount = WriteOut.size();
        WriteOut.append("\n");
        for (int i = 0; i < Underscorecount; i++)
        {
            WriteOut.append("_");
        }
        WriteOut.append("\n");

        int DigitCount =  (int)(log10(TempA) + 1);
        for (int i = 0; i < (int)((Underscorecount - DigitCount) / 3); i++)
        {
            WriteOut.append(" ");
        }
        WriteOut.append(std::to_string(TempA));
        WrittenOut = (char*)WriteOut.c_str();
        RootIsNumber = false;
        return;
    }

    cout << Descrim << endl;

    // If the descriminate is == 0, there will be 1 root
    if (Descrim == 0)
    {
        RootIsNumber = true;
        Roots[0] = 1;
        Roots[1] = Fraction(TempB,TempA);
    }
    else // If the descriminate is equal to 1 or more then there will be 2 roots
    {
        RootIsNumber = true;
        Roots[0] = 2;
        Roots[1] = Fraction((TempB - NewD.GetCoef()),TempA);
        Roots[2] = Fraction((TempB + NewD.GetCoef()),TempA);
    }
}

// Char output for printing
string Parabola::out()
{
    CalculateRoots();
    bool NoRoot = false;
    string SOut;

    Fraction Temp1 = Roots[1];
    Fraction Temp2 = Roots[2];

    if (Roots[0] == 0)
    {
        SOut.append("there are no roots.");
        NoRoot = true;
    }

    if (NoRoot) {}
    else if (this->IsRootNumber())
    {
        SOut.append("The first root is ").append(Roots[1].out());
        if (Roots[0] > 1) SOut.append(" and the second root is ").append(Roots[2].out());
    }
    else
    {
        SOut = WrittenOut;
    }

    return SOut.c_str();
}