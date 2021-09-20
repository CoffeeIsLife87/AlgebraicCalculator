#include "Term.h"
#include <iostream>

bool TempContains[26];

std::map<char,signed int> Term::SimplifyTerm(std::vector<VarExpo> VList)
{
    std::map<char,signed int> PassBack;
    for( char c : "abcdefghijklmnopqrstuvwxyz") { // for every letter in the alphabet
        cout << (int)c << endl;
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

Term::Term(Fraction Coefficient, std::vector<VarExpo> VList, Fraction Exponent): 
    Coef(Coefficient), VarList(SimplifyTerm(VList)), Contains({TempContains})
{
    // There's not much to do on construction except for fill in const values
    // so for now this is fine empty
}

// WIP

bool Term::IsCompatible(Term Check)
{
    
}

vector<Term> Term::AddTerm(Term ToAdd)
{
    vector<Term> ret; // ret is return. The final value we send out

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
}

vector<Term> Term::SubTerm(Term ToSub)
{
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
}

Term MultiplyTerm(Term ToMultiply)
{
    // Algebra doesn't care how many variables or exponents or coefficients you have. 
    // Multiplying a term by a term should get you 1 term.
}

ostream operator<< (ostream &out, Term T)
{
    //out << c.real;
    //out << "+i" << c.imag << endl;
//
    //string CoutPoly = string().append(
    //    T.Coef.isWhole()? 
    //    std::to_string(T.Coef.GetWhole()): 
    //    string().append(std::to_string(T.Coef.GetTopHalf()).append("/").append(std::to_string(T.Coef.GetBottomHalf()))))
    //    .append(PN.VarLetter)
    //    .append(
    //    PN.Expo.isWhole? 
    //    std::string("^").append(std::to_string(PN.Expo.GetWhole())): 
    //    string().append(std::to_string(PN.Expo.TopHalf).append("/").append(std::to_string(PN.Expo.BottomHalf)))
    //    );
}