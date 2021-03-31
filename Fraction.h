#pragma once
#include <vector>
#include <string>

using namespace std;

class Fraction
{
	/*-------------------------------------------------------------------------*\
	| Represents a BASIC fraction. Cannot have unknowns or more than 1 number   |
	|																			|
	| Supports all of the basic operations										|
	\*-------------------------------------------------------------------------*/
public:
	Fraction(int TopHalf, int BottomHalf);
	
	Fraction AddFraction(Fraction ToAdd);
	Fraction SubtractFraction(Fraction ToSubtract);

	Fraction MultiplyFraction(Fraction ToMultiply);
	Fraction DevideFraction(Fraction ToDevide);

	const int Mixed;
	const int TopHalf;
	const int BottomHalf;
};

class FractionAddSubtract
{

};

