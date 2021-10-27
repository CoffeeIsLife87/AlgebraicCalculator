#include <cmath>
#include "Radical.hpp"

using namespace std;

class Parabola
{
public:
    // "Constructor" For Standard form
    static Parabola ParabolaABC(int A, int B, int C);
    // "Constructor" For Vertex form
    static Parabola ParabolaHK(int A, int H, int K);
    // "Constructor" for Factored form
    static Parabola ParabolaPQ(int A, int P, int Q);

    int GetDescriminate();

    const bool IsRootNumber();
    const Fraction* GetRoots();
    // This will return at most 3 values. The first item is the return count. The second is the left root (or only), the third item is the right root
    void CalculateRoots();

    string out();

private:
    Parabola(){};

    // A(0), B(1), C(2), H(3), K(4), P(5), Q(6)
    bool Init[7] = {false};
    signed int A, B, C, H, K, P, Q;

    bool OpensUp = true;

    bool RootIsNumber = false;
    Fraction* Roots = new Fraction[3];
    char* WrittenOut;

    Fraction  GetAoS();
    Fraction* GetVertex(Fraction X);
};

inline Parabola Parabola::ParabolaABC(int A, int B, int C)
{
    /*-----------------------------------------------*\
    | y = AX^2 + BX + C                               |
    \*-----------------------------------------------*/

    Parabola ret = Parabola();
    for (int i = 0; i < 3; i++){ret.Init[i] = true;}
    ret.A = A; ret.Init[0] == true;
    ret.B = B; ret.Init[1] == true;
    ret.C = C; ret.Init[2] == true;
    return ret;
}

inline Parabola Parabola::ParabolaHK(int A, int H, int K)
{
    /*--------------------------------------------*\
    | y = (a * (x - h)^2) + k                       |
    | The H represents the X point in the vertex   |
    | The K represents the Y point in the vertex   |
    \*--------------------------------------------*/
    Parabola ret = Parabola();
    // We need to do the squaring first so we'll do that
    // It ends up looking like (x - h)(x - h)
    // so we'll have X^2, h*h, h*x, h*x
    // Then we multiply all of those by A

    // A is A :)
    ret.A = A; ret.Init[0] = true;
    ret.H = H; ret.Init[3] = true;
    ret.K = K; ret.Init[4] = true;

    // B = H*X. This doesn't become X^2. So we can assume that this will be B
    ret.B = (-H * A) + (-H * A); ret.Init[1] = true;
    // There isn't an X here. So we can assume that this is C
    ret.C = ((-H * -H) * A) + K; ret.Init[2] = true;

    if (A < 0){ret.OpensUp = false;}

    return ret;
}

inline Parabola Parabola::ParabolaPQ(int A, int P, int Q)
{
    Parabola ret = Parabola();
    /*
    | y = A(x - p)(x - q)
    | Time to start distributing
    | x * x, -p * -q, (x * p, x * q) 
    | We combine the last 2 terms because they have the same variables
    | We'll also need to multiply everything by A
                                    */
    ret.A = A;                      ret.Init[0] = true;
    ret.B = ((A * -P) + (A * -Q)); ret.Init[1] = true;
    ret.C = (A * (-P * -Q));        ret.Init[2] = true;
    ret.P = P;                      ret.Init[5] = true;
    ret.Q = Q;                      ret.Init[6] = true;

    return ret;
}

Fraction Parabola::GetAoS()
{
    Fraction Ret = Fraction((this->B * -1) , (this->A * 2));
    Ret.SimplifyFraction();
    return Ret;
}

Fraction* Parabola::GetVertex(Fraction X)
{
    Fraction F1;
    F1 = (Fraction)this->A * (X * X);

    Fraction F2;
    F2 =  (Fraction)this->B * X;

    Fraction Y = F1 + F2 + this->C;
    Fraction* Ret = new Fraction[2];
    if (X.isWhole()) H = X.GetWhole(); Init[3] = true;
    if (Y.isWhole()) K = Y.GetWhole(); Init[4] = true;

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

void Parabola::CalculateRoots()
{
    //if (Init[0] && Init[1] && Init[2])

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
        string WriteOut;
        WriteOut.append(to_string((signed int)B));
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
        WriteOut.append(to_string(TempA));
        WrittenOut = (char*)WriteOut.c_str();
        RootIsNumber = false;
        return;
    }

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

// True + & False -
const char* sign(int check, bool initial){

    if (  (!initial && (check < 0) )  ||  (initial && (check >= 0) )  ){ // subtraction and negative number or addition and positive number
        return string("+ ").append(to_string(abs(check))).c_str();
    }
    if (  (!initial && (check >= 0) )  ||  (initial && (check < 0) )  ){ // subtraction and positive number or addition and negative number
        return string("- ").append(to_string(abs(check))).c_str();
    }
    return "";
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

    SOut.append("\n");

    SOut.append("Descriminate: ")               \
    .append(to_string(this->GetDescriminate())) \
    .append("\n");

    Fraction* V = this->GetVertex(this->GetAoS());
    SOut.append("Vertex: (") \
    .append(V[0].out())      \
    .append(", ")            \
    .append(V[1].out())      \
    .append(")\n");

    SOut.append("AoS: ") \
    .append(V[0].out())  \
    .append("\n");

    if (OpensUp)
    {
        SOut.append("Parabola Opens Up\n");
    }
    else
    {
        SOut.append("Parabola Opens Down\n");
    }

    // Write standard form conversion
    if (Init[0] && Init[1] && Init[2])
    {
        SOut.append("Standard Form: ")                                   \
        .append(to_string(A)) /* A                                   */  \
        .append("X^2 ")       /* A(X^2)                              */  \
        .append(sign(B,true)) /* A(X^2) < + or - > B                 */  \
        .append("x ")         /* A(X^2) < + or - > B(X)              */  \
        .append(sign(C,true)) /* A(X^2) < + or - > B(X) < + or - > C */  \
        .append("\n");
    }

    // Write vertex form conversion
    if (Init[0] && Init[3] && Init[4])
    {
        SOut.append("Vertex Form: ")                                    \
        .append(to_string(A))  /* A                                  */ \
        .append("(X ")         /* A( X                               */ \
        .append(sign(H,false)) /* A( X < + or - > H                  */ \
        .append(")^2 ")        /* A( X < + or - > H )^2              */ \
        .append(sign(K,true))  /* A( X < + or - > H )^2 < + or - > K */ \
        .append("\n");
    }

    // Write Factored form conversion
    if (Init[0] && Init[5] && Init[6])
    {
        SOut.append("Factored Form: ")                                        \
        .append(to_string(A))     /* A                                     */ \
        .append("(x ")            /* A(x )                                 */ \
        .append(sign(P,false))    /* A( X < + or - > P                     */ \
        .append(")(x")            /* A( X < + or - > P )( X )              */ \
        .append(sign(Q,false))    /* A( X < + or - > P )( X < + or - > Q   */ \
        .append(")\n");           /* A( X < + or - > P )( X < + or - > Q ) */ \
    }

    return SOut.c_str();
}