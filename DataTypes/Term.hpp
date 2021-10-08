#include <vector>
#include <map>
#include "Fraction.hpp"

typedef struct VarExpo {
    char VarLetter;
    Fraction Expo = Fraction(0,1);
} VarExpo;

class Term
{
    /*----------------------------------------------------------*\
    | A Term is a term with a coefficient and a variable.        |
    | And sometimes an exponent                                  |
    | [ 6x^2. Funtioning as 6(x * x) ]                           |
    \*----------------------------------------------------------*/
public:
    Term(Fraction Coefficient, std::vector<VarExpo> VList);
    const std::map<char, Fraction> GetVarList();
    // (Step 3) const char* out();

    // You can subtract by just swapping symbols. So subtracting a negative is just addition.
    vector<Term> operator+(Term ToAdd);
    
    //vector<Term> SubTerm(Term ToSub);
    
    //Term MultiplyTerm(Term ToMultiply);
	
    //Term DevideTerm(Term ToDevide);

private:
    std::map<char, Fraction> VarList;
    Fraction Coef;

    bool IsCompatible(Term); // Step 2
};


Term::Term(Fraction Coefficient, std::vector<VarExpo> VList)
{
    std::map<char,signed int> PassBack;
    for( char c : "abcdefghijklmnopqrstuvwxyz") { // for every letter in the alphabet
        Fraction FExpo = Fraction(0,1); // Signed can do negative
        for (int v = 0; v < (int)VList.size(); v++)
        {
            if (VList[v].VarLetter == c)
            {
                FExpo += (VList[v].Expo);
            }
        }

        if (FExpo != 0)
        {
            PassBack.emplace(c,FExpo);
            //TempContains[ToAlphaPos(c)] = true;
        }
        FExpo = 0;
    }
}

// WIP

const std::map<char, Fraction> Term::GetVarList()
{
    return this->VarList;
}

bool Term::IsCompatible(Term Check)
{
    std::map<char, Fraction> ExtVL = Check.GetVarList();
    if (this->VarList.size() != ExtVL.size() )
    {
        return false;
    }

    for (auto it = this->VarList.begin(); it != this->VarList.end(); it++)
    {
        cout << it->first << endl;
        //if (ExtVL.find())
        //{
        //    
        //}
    }
    return true;
}

vector<Term> Term::AddTerm(Term ToAdd)
{
    vector<Term> ret; // ret is return. The final value we send out
    if (!IsCompatible(ToAdd))
    {
        ret.push_back(*this);
        ret.push_back(ToAdd);
    }
    // Make sure both fractions are simplified already
    //Fraction ExpoSimp = this->Expo.SimplifyFraction();
    //Fraction CheckExpoSimp = ToAdd.Expo.SimplifyFraction();
//
    //// If the Exponents and variables are the same then continue (Adding Terms is only legal if both of those are the same)
    //if ((this->VarLetter == ToAdd.VarLetter)
    //    /* Check letters to make sure they relate at all */ &&
    //    ((ExpoSimp.TopHalf == CheckExpoSimp.TopHalf) && (ExpoSimp.BottomHalf == CheckExpoSimp.BottomHalf))
    //)
    //{
    //    // Since all of the items in polynomails are storeed as fractions I just used the addFraction functions
    //    Fraction NewCoef = this->Coef.AddFraction(ToAdd.Coef);
//
    //    // Send the one back
    //    ret.push_back(Term(NewCoef,this->VarLetter,this->Expo));
    //    return ret;
    //}
    //else
    //{
    //    // send them both back 
    //    ret.push_back(*this);
    //    ret.push_back(ToAdd);
    //    return ret;
    //}
    return ret;
}

//vector<Term> Term::SubTerm(Term ToSub)
//{
    //vector<Term> ret; // ret is return. The final value we send out
//
    //// Make sure both fractions are simplified already
    //Fraction ExpoSimp = this->Expo.SimplifyFraction();
    //Fraction CheckExpoSimp = ToSub.Expo.SimplifyFraction();
//
    //// If the Exponents and variables are the same then continue (Adding Terms is only legal if both of those are the same)
    //if ((this->VarLetter == ToSub.VarLetter)
    //    /* Check letters to make sure they relate at all */ &&
    //    ((ExpoSimp.TopHalf == CheckExpoSimp.TopHalf) && (ExpoSimp.BottomHalf == CheckExpoSimp.BottomHalf))
    //)
    //{
    //    // Since all of the items in polynomails are storeed as fractions I just used the addFraction functions
    //    Fraction NewCoef = this->Coef.SubtractFraction(ToSub.Coef);
//
    //    // Send the one back
    //    ret.push_back(Term(NewCoef,this->VarLetter,this->Expo));
    //    return ret;
    //}
    //else
    //{
    //    // send them both back 
    //    ret.push_back(*this);
    //    ret.push_back(ToSub);
    //    return ret;
    //}
//}

//Term MultiplyTerm(Term ToMultiply)
//{
//    // Algebra doesn't care how many variables or exponents or coefficients you have. 
//    // Multiplying a term by a term should get you 1 term.
//}

//const char* Term::out()
//{
//    string CoutPoly;
//    // Add Coefficient
//    CoutPoly.append( this->Coef.isWhole() ? to_string(this->Coef.GetWhole()) : this->Coef.out() );
//
//    // Add variables
//}