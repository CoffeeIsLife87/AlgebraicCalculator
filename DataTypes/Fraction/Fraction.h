#pragma once
#include <vector>
#include <iostream>

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
	Fraction(int Whole);

	void operator=(int Num) {
		this->TopHalf = Num;
		this->BottomHalf = 1;
	}
	void operator=(Fraction F)
	{
		this->TopHalf = F.GetTopHalf();
		this->BottomHalf = F.GetBottomHalf();
	}

	void operator+=(Fraction ToAdd);
	Fraction operator+(Fraction ToAdd);

	void operator-=(Fraction ToSubtract);
	Fraction operator-(Fraction ToSubtract);

	void operator*=(Fraction ToMultiply);
	Fraction operator*(Fraction ToMultiply);

	void operator/=(Fraction ToDevide);
	Fraction operator/(Fraction ToDevide);

	const int GetTopHalf()    {return this->TopHalf;};
	const int GetBottomHalf() {return this->BottomHalf;};
	const bool isWhole()      {return (TopHalf % BottomHalf == 0 ? true : false); };
	const int GetWhole()      {return isWhole() ? (TopHalf / BottomHalf) : 0;};

	void SimplifyFraction();

	bool operator!=(Fraction F) {
		F.SimplifyFraction();
		this->SimplifyFraction();
		
		if ((F.TopHalf == this->TopHalf) || (F.BottomHalf == this->BottomHalf))
		{
			return false;
		} else {
			return true;
		}
	}
	bool operator==(Fraction F) {
		F.SimplifyFraction();
		this->SimplifyFraction();
		
		if ((F.TopHalf == this->TopHalf) && (F.BottomHalf == this->BottomHalf))
		{
			return true;
		} else {
			return false;
		}
	}

	const char* out();

private:
	int TopHalf;
	int BottomHalf;

	signed int CreateCommonBottom(int LeftBottom, int RightBottom);
};
