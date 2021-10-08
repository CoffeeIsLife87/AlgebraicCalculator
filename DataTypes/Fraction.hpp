#include <vector>
#include <iostream>
#pragma once
using namespace std;

vector<int> PrimeList = { 2, 3, 5, 7, 11, 13 };

class Fraction
{
	/*-------------------------------------------------------------------------*\
	| Represents a BASIC fraction. Cannot have unknowns or more than 1 number   |
	|																			|
	| Supports all of the basic operations										|
	\*-------------------------------------------------------------------------*/
public:
	Fraction(int TopHalf, int BottomHalf);

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

/*------------------------------------------------------------------------------------------------------*\
| There isn't anything that would need to go in the constructors so I am just going to leave them empty  |
\*------------------------------------------------------------------------------------------------------*/
Fraction::Fraction(int TH = 0, int BH = 1): 
	TopHalf(TH), BottomHalf(BH){}

vector<int> GetPrimes(int Num)
{
	vector<int> Primes;
	int TmpNum = Num;
	while (true)
	{
		if ((TmpNum % 2) == 0)
		{
			TmpNum = TmpNum / 2;
			Primes.push_back(2);
			continue;
		}
		else if ((TmpNum % 3) == 0)
		{
			TmpNum = TmpNum / 3;
			Primes.push_back(3);
			continue;
		}
		else if ((TmpNum % 5) == 0)
		{
			TmpNum = TmpNum / 5;
			Primes.push_back(5);
			continue;
		}
		else if ((TmpNum % 7) == 0)
		{
			TmpNum = TmpNum / 7;
			Primes.push_back(7);
			continue;
		}
		else if ((TmpNum % 11) == 0)
		{
			TmpNum = TmpNum / 11;
			Primes.push_back(11);
			continue;
		}
		else if ((TmpNum % 13) == 0)
		{
			TmpNum = TmpNum / 13;
			Primes.push_back(13);
			continue;
		}
		else
		{
			return Primes;
		}
	}
}


signed int Fraction::CreateCommonBottom(int LeftBottom, int RightBottom)
{	
	vector<int> LeftPrimes = GetPrimes(LeftBottom);
	vector<int> RightPrimes = GetPrimes(RightBottom);

	int FinalBottom = 1;

	for (int PrimeID = 0; PrimeID < (int)PrimeList.size(); PrimeID++)
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
void Fraction::SimplifyFraction()
{
	int SimpTopHalf    = 1;
	int SimpBottomHalf = 1;

	vector<int> TopHalfPrimes = GetPrimes(this->TopHalf);
	vector<int> BottomHalfPrimes = GetPrimes(this->BottomHalf);

	int TopHalfPCount[6] = {0,0,0,0,0,0};
	int BottomHalfPCount[6] = {0,0,0,0,0,0};

	// Count amount of specific primes per half
	for (int i = 0; i < (int)TopHalfPrimes.size(); i++)
	{
		for (int p = 0; p < (int)PrimeList.size(); p++) // p is the index of the prime in PrimeList
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
		for (int p = 0; p < (int)PrimeList.size(); p++) // p is the index of the prime in PrimeList
		{
			if (BottomHalfPrimes[i] == PrimeList[p])
			{
				BottomHalfPCount[p] += 1;
				break;
			}
		}
	}

	for (int i = 0; i < 6; i++)
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

	this->TopHalf = SimpTopHalf;
	this->BottomHalf = SimpBottomHalf;
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

const char* Fraction::out()
{
	string SOut;
	SOut.append(to_string(this->GetTopHalf()));
	SOut.append("/");
	SOut.append(to_string(this->GetBottomHalf()));

	return SOut.c_str();
}