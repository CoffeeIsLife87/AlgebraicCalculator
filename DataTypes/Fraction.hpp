#include <vector>
#include <iostream>
#include "Primes.hpp"
using namespace std;
using namespace Primes;

#pragma once

class Fraction
{
	/*-------------------------------------------------------------------------*\
	| Represents a BASIC fraction. Cannot have unknowns or more than 1 number   |
	|																			|
	| Supports all of the basic operations										|
	\*-------------------------------------------------------------------------*/
public:
	Fraction(int TopHalf, int BottomHalf);

	// Direct Assignment
	void operator=(int Num);
	void operator=(Fraction F);

	// Addition
	void operator+=(Fraction ToAdd);
	Fraction operator+(Fraction ToAdd);

	// Subtraction
	void operator-=(Fraction ToSubtract);
	Fraction operator-(Fraction ToSubtract);

	// Multiplication
	void operator*=(Fraction ToMultiply);
	Fraction operator*(Fraction ToMultiply);

	// Devision
	void operator/=(Fraction ToDevide);
	Fraction operator/(Fraction ToDevide);

	// Value retrieval
	const int GetTopHalf()    {return this->TopHalf;};
	const int GetBottomHalf() {return this->BottomHalf;};
	const bool isWhole()      {return (TopHalf % BottomHalf == 0 ? true : false); };
	const int GetWhole()      {return isWhole() ? (TopHalf / BottomHalf) : 0;};

	// Equal operators
	bool operator==(Fraction F);
	bool operator!=(Fraction F);

	// Greater than operators
	bool operator>(Fraction F);
	bool operator>=(Fraction F);

	// Less than operators
	bool operator<(Fraction F);
	bool operator<=(Fraction F);
	
	// Simplify the fraction
	void SimplifyFraction();
	// Give characters to output for use in cout
	const char* out();

private:
	int TopHalf;
	int BottomHalf;

	// Find common denominator
	signed int CreateCommonBottom(int LeftBottom, int RightBottom);
	// Just get the tops over the denominator
	int* GetCommonTop(Fraction F);
};

/*------------------------------------------------------------------------------------------------------*\
| There isn't anything that would need to go in the constructors so I am just going to leave them empty  |
\*------------------------------------------------------------------------------------------------------*/
Fraction::Fraction(int TH = 0, int BH = 1): 
	TopHalf(TH), BottomHalf(BH){}

void Fraction::operator=(int Num) {
	this->TopHalf = Num;
	this->BottomHalf = 1;
}
void Fraction::operator=(Fraction F)
{
	this->TopHalf = F.GetTopHalf();
	this->BottomHalf = F.GetBottomHalf();
}

void Fraction::operator+=(Fraction ToAdd)
{
	if (ToAdd.GetBottomHalf() == this->BottomHalf)
	{
		this->TopHalf = ToAdd.GetTopHalf() + this->TopHalf;
		return;
	}

	int LeftBottom = ToAdd.GetBottomHalf();
	int RightBottom = this->BottomHalf;
	int FinalBottom = CreateCommonBottom(LeftBottom, RightBottom);

	int LTop = (ToAdd.GetTopHalf() * (FinalBottom / LeftBottom));
	int RTop = (this->TopHalf * (FinalBottom / RightBottom));

	this->BottomHalf = FinalBottom;
	this->TopHalf = LTop + RTop;
};
Fraction Fraction::operator+(Fraction ToAdd)
{
	if (ToAdd.GetBottomHalf() == this->BottomHalf)
	{
		return Fraction((ToAdd.GetTopHalf() + this->TopHalf), this->BottomHalf);
	}

	int LeftBottom = ToAdd.GetBottomHalf();
	int RightBottom = this->BottomHalf;
	int FinalBottom = CreateCommonBottom(LeftBottom, RightBottom);

	int LTop = (ToAdd.GetTopHalf() * (FinalBottom / LeftBottom));
	int RTop = (this->TopHalf * (FinalBottom / RightBottom));

	return Fraction((LTop + RTop), FinalBottom);
};

void Fraction::operator-=(Fraction ToSubtract)
{
	if (ToSubtract.GetBottomHalf() == this->BottomHalf)
	{
		this->TopHalf = this->TopHalf - ToSubtract.GetTopHalf();
	}

	int BottomToSub = ToSubtract.GetBottomHalf();
	int BottomToSubFrom = this->BottomHalf;
	int FinalBottom = CreateCommonBottom(BottomToSub, BottomToSubFrom);

	int TopToSub = (ToSubtract.TopHalf * (FinalBottom / BottomToSub));
	int TopToSubFrom = (this->TopHalf * (FinalBottom / BottomToSubFrom));

	this->TopHalf = TopToSubFrom - TopToSub;
	this->BottomHalf = FinalBottom;
};
Fraction Fraction::operator-(Fraction ToSubtract)
{
	if (ToSubtract.GetBottomHalf() == this->BottomHalf)
	{
		return Fraction((this->TopHalf - ToSubtract.GetTopHalf()), this->BottomHalf);
	}

	int BottomToSub = ToSubtract.GetBottomHalf();
	int BottomToSubFrom = this->BottomHalf;
	int FinalBottom = CreateCommonBottom(BottomToSub, BottomToSubFrom);

	int TopToSub = (ToSubtract.TopHalf * (FinalBottom / BottomToSub));
	int TopToSubFrom = (this->TopHalf * (FinalBottom / BottomToSubFrom));

	return Fraction((TopToSubFrom - TopToSub), FinalBottom);
};

void Fraction::operator*=(Fraction ToMultiply)
{
	this->TopHalf = this->TopHalf * ToMultiply.GetTopHalf();
	this->BottomHalf = this->BottomHalf * ToMultiply.GetBottomHalf();
}
Fraction Fraction::operator*(Fraction ToMultiply)
{
	return Fraction((this->TopHalf * ToMultiply.GetTopHalf()), (this->BottomHalf * ToMultiply.GetBottomHalf()));
}

void Fraction::operator/=(Fraction ToDevide)
{
	this->TopHalf    = this->TopHalf * ToDevide.GetBottomHalf();
	this->BottomHalf = this->BottomHalf * ToDevide.GetTopHalf();
}
Fraction Fraction::operator/(Fraction ToDevide)
{
	return Fraction((this->TopHalf * ToDevide.GetBottomHalf()), (this->BottomHalf * ToDevide.GetTopHalf()));
}

bool Fraction::operator==(Fraction F)
{
	F.SimplifyFraction();
	this->SimplifyFraction();
	
	if ((F.TopHalf == this->TopHalf) && (F.BottomHalf == this->BottomHalf))
	{
		return true;
	}
	return false;
}
bool Fraction::operator!=(Fraction F)
{
	return !(F == *this);
}

bool Fraction::operator>(Fraction F)
{
	int* Nums = GetCommonTop(F);
	
	signed int OTop = Nums[0];
	signed int CTop = Nums[1];
	
	if (OTop > CTop)
	{
		return true;
	}
	return false;
}
bool Fraction::operator>=(Fraction F) 
{
	if ((*this == F) || (*this > F))
	{
		return true;
	}
	return false;
}

bool Fraction::operator<(Fraction F) 
{
	int* Nums = GetCommonTop(F);
	signed int OTop = Nums[0];
	signed int CTop = Nums[1];

	if (OTop < CTop)
	{
		return true;
	}
	return false;
	}
bool Fraction::operator<=(Fraction F)
{
	if ((*this == F) || (*this < F))
	{
		return true;
	}
	return false;
}

void Fraction::SimplifyFraction()
{
	bool IsTopNegative = (this->TopHalf < 0);
	bool IsBottomNegative = (this->BottomHalf < 0);
	int SimpTopHalf    = 1;
	int SimpBottomHalf = 1;

	vector<int> TopHalfPrimes = GetPrimes(this->TopHalf);
	vector<int> BottomHalfPrimes = GetPrimes(this->BottomHalf);

	int TopHalfPCount[6] = {0,0,0,0,0,0};
	int BottomHalfPCount[6] = {0,0,0,0,0,0};

	// Count amount of specific primes per half
	for (int i = 0; i < (int)TopHalfPrimes.size(); i++)
	{
		for (int p = 0; p < PLSize; p++) // p is the index of the prime in PrimeList
		{
			if (TopHalfPrimes[i] == PrimeList[p])
			{
				TopHalfPCount[p] += 1;
				break;
			}
		}
	}
	for (int i = 0; i < (int)BottomHalfPrimes.size(); i++)
	{
		for (int p = 0; p < PLSize; p++) // p is the index of the prime in PrimeList
		{
			if (BottomHalfPrimes[i] == PrimeList[p])
			{
				BottomHalfPCount[p] += 1;
				break;
			}
		}
	}

	for (int i = 0; i < 6; i++) // What?
	{
		if (TopHalfPCount[i] > BottomHalfPCount[i])
		{
			int GoBy = TopHalfPCount[i] - BottomHalfPCount[i];
			for (int m = 0; m < GoBy; m++)
			{
				SimpTopHalf *= PrimeList[i];
			}
		}
		else if (TopHalfPCount[i] < BottomHalfPCount[i])
		{
			int GoBy = BottomHalfPCount[i] - TopHalfPCount[i];
			for (int m = 0; m < GoBy; m++)
			{
				SimpBottomHalf *= PrimeList[i];
			}
		}
		else if (TopHalfPCount[i] == BottomHalfPCount[i])
		{
			continue;
		}
	}

	if (IsTopNegative && IsBottomNegative){}
	else if (IsTopNegative && !IsBottomNegative)
	{
		SimpTopHalf = SimpTopHalf * -1;
	}
	else if (!IsTopNegative && IsBottomNegative)
	{
		SimpTopHalf = SimpTopHalf * -1;
	}
	this->TopHalf = SimpTopHalf;
	this->BottomHalf = SimpBottomHalf;

}
const char* Fraction::out()
{
	this->SimplifyFraction();
	string SOut;
	SOut.append(to_string((signed int)this->TopHalf));
	if (this->BottomHalf != 1)
	{
		SOut.append("/");
		SOut.append(to_string((signed int)this->BottomHalf));
	}

	return SOut.c_str();
}

signed int Fraction::CreateCommonBottom(int LeftBottom, int RightBottom)
{	
	vector<int> LeftPrimes = GetPrimes(LeftBottom);
	vector<int> RightPrimes = GetPrimes(RightBottom);

	int FinalBottom = 1;

	for (int PrimeID = 0; PrimeID < PLSize; PrimeID++)
	{
		int LeftPrimeCount  = 0;
		int RightPrimeCount = 0;

		for (int LeftPrimeID = 0; LeftPrimeID < (int)LeftPrimes.size(); LeftPrimeID++)
		{
			if (LeftPrimes[LeftPrimeID] == PrimeList[PrimeID])
			{
				LeftPrimeCount++;
			}
			if (LeftPrimes[LeftPrimeID] > PrimeList[PrimeID])
			{
				break;
			}
		}
		for (int RightPrimeID = 0; RightPrimeID < (int)RightPrimes.size(); RightPrimeID++)
		{
			if (RightPrimes[RightPrimeID] == PrimeList[PrimeID])
			{
				RightPrimeCount++;
			}
			if (RightPrimes[RightPrimeID] > PrimeList[PrimeID])
			{
				break;
			}
		}

		int PrimeCount = (LeftPrimeCount > RightPrimeCount ? LeftPrimeCount : RightPrimeCount);
		if ((PrimeList[PrimeID] * PrimeCount) > 0)
		{
			FinalBottom *= (PrimeList[PrimeID] * PrimeCount);
		}
		
		LeftPrimeCount = 0;
		RightPrimeCount = 0;
	}
	return FinalBottom;
}
int* Fraction::GetCommonTop(Fraction F)
{

		// Original is the number on the left
		int OriginalBottom = this->BottomHalf;

		// This is the number on the right
		int CompareBottom = F.GetBottomHalf();

		// Common bottom
		int FinalBottom = CreateCommonBottom(OriginalBottom, CompareBottom);

		int OTop = (this->TopHalf * (FinalBottom / OriginalBottom));
		int CTop = (F.GetTopHalf() * (FinalBottom / CompareBottom));

		//cout << std::to_string(OTop) << endl;
		//cout << std::to_string(CTop) << endl;

		int* Ret = new int[2];
		Ret[0] = OTop; // original Top
		Ret[1] = CTop; // Compared Top

		return Ret;
	};
