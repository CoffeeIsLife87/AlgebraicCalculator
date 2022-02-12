#include <vector>
#include <map>
#include "Fraction.hpp"

typedef std::map<char,Fraction> VarExpo;

static VarExpo MakeVList(vector<char> characters, vector<Fraction> Exponents)
{
    if (characters.size() != Exponents.size()) {
        std::__throw_out_of_range("Character and Exponent list aren't the same size");
    }
    VarExpo ReturnVList;
    for (size_t charCounter = 0; charCounter < characters.size(); charCounter++)
    {
        char CurrentChar = characters[charCounter];
        Fraction CurrentExpo = Exponents[charCounter];
        // If we can't find the value we'll emplace it into the list
        if ( ReturnVList.find(CurrentChar) == ReturnVList.end() ) {
            ReturnVList.emplace(CurrentChar,CurrentExpo);
        }
        else {
            ReturnVList[CurrentChar] += CurrentExpo;
        }
    }
    return ReturnVList;
}

/*----------------------------------------------------------*\
| A Term is a term with a coefficient and a variable.        |
| And sometimes an exponent                                  |
| [ 6x^2. Funtioning as 6(x * x) ]                           |
\*----------------------------------------------------------*/
class Term
{
public:
    Term(Fraction Coefficient, VarExpo VList);
    const VarExpo GetVarList();
    bool IsCompatible(Term);
    string out();

    //vector<Term> operator+(Term ToAdd);
    
    //vector<Term> operator-(Term ToSub);
    
    //Term MultiplyTerm(Term ToMultiply);
	
    //Term DevideTerm(Term ToDevide);

private:
    VarExpo VarList;
    Fraction Coef;
};

Term::Term(Fraction Coefficient, VarExpo VList)
{
    Coef = Coefficient;
    VarList = VList;
}

// WIP

const std::map<char, Fraction> Term::GetVarList()
{
    return this->VarList;
}

bool Term::IsCompatible(Term Check)
{
    if (this->VarList.size() != Check.GetVarList().size() )
    {
        return false;
    }

    VarExpo TempCheck = Check.GetVarList();

    for (auto it = this->VarList.begin(); it != this->VarList.end(); it++) {
        if (TempCheck.find(it->first) == TempCheck.end() ) {
            return false;
        } else if ((Fraction)(TempCheck.at(it->first)) == (Fraction)it->second) {
            continue;
        }
    }
    return true;
}

//vector<Term> Term::operator+(Term ToAdd)
//{
//    return ret;
//}
//vector<Term> Term::operator-(Term ToSub)
//{
//    return 
//}

//Term MultiplyTerm(Term ToMultiply)
//{
//    // Algebra doesn't care how many variables or exponents or coefficients you have. 
//    // Multiplying a term by a term should get you 1 term.
//}

string Term::out()
{
    string CoutPoly;
    // Add Coefficient
    CoutPoly.append( this->Coef.isWhole() ? to_string(this->Coef.GetWhole()) : this->Coef.out() );

    // Add variables
    for (auto it = this->VarList.begin(); it != this->VarList.end(); it++)
    {
        CoutPoly.append(sizeof(it->first) , it->first );
        CoutPoly.append("^").append(it->second.out());
    }

    return CoutPoly;
}