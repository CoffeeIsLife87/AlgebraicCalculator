#include <iostream>
//#include "Term.cpp"
#include "Fraction.cpp"
using namespace std;

int main()
{
    //Term PN1 = Term(Fraction(5,1),(char*)"x",Fraction(2,1));
    //Term PN2 = Term(Fraction(-8,1),(char*)"x",Fraction(2,1));
    //vector<Term> AddPNs = PN1.SubTerm(PN2); // should get 13(x^2)
    //for (int i = 0; i < AddPNs.size(); i++)
    //{
    //    Term PN = AddPNs[i];
    //    
    //    string CoutPoly = string().append(
    //        PN.Coef.isWhole? 
    //        std::to_string(PN.Coef.GetWhole()): 
    //        string().append(std::to_string(PN.Coef.TopHalf).append("/").append(std::to_string(PN.Coef.BottomHalf))))
    //        .append(PN.VarLetter)
    //        .append(
    //        PN.Expo.isWhole? 
    //        std::string("^").append(std::to_string(PN.Expo.GetWhole())): 
    //        string().append(std::to_string(PN.Expo.TopHalf).append("/").append(std::to_string(PN.Expo.BottomHalf)))
    //        );
    //    cout << CoutPoly << endl;
    //}

    Fraction F = Fraction(1,2);

    F += Fraction(1,3);

    cout << F.out() << endl;

    return 0;
}
