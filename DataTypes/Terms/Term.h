#pragma once
#include <vector>
#include <map>
#include "../Fraction/Fraction.cpp"

// NON FUNCTIONING

typedef struct VarExpo {
    char VarLetter;
    Fraction Expo;
};

class Term
{
    /*----------------------------------------------------------*\
    | A Term is a term with a coefficient and a variable.        |
    | And sometimes an exponent                                  |
    | [ 6x^2. Funtioning as 6(x * x) ]                           |
    \*----------------------------------------------------------*/
public:
    Term(Fraction Coefficient, std::vector<VarExpo> VList, Fraction Exponent);

    // You can subtract by just swapping symbols. So subtracting a negative is just addition.
    vector<Term> AddTerm(Term ToAdd);
    vector<Term> SubTerm(Term ToSub);
    Term MultiplyTerm(Term ToMultiply);
	//Term DevideTerm(Term ToDevide);

    const bool Contains[26];
    const std::map<char,signed int> VarList;

    Fraction Coef;

private:
    std::map<char,signed int> SimplifyTerm(std::vector<VarExpo> VList);
    bool IsCompatible(Term);
};