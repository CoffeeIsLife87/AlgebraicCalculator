#include "Fraction.h"

vector<int> PrimeList = { 2, 3, 5, 7, 11, 13 };

Fraction::Fraction(int TH, int BH): 
	TopHalf(TH), BottomHalf(BH), Mixed(-1)
{
	/*-------------------------------------------------------------------------------------*\
	| There isn't anything that would need to go here so I am just going to leave it empty  |
	\*-------------------------------------------------------------------------------------*/
}

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

Fraction Fraction::AddFraction(Fraction ToAdd)
{
	if (ToAdd.BottomHalf == this->BottomHalf)
	{
		int Top = ToAdd.TopHalf + this->TopHalf;
		Fraction RetFraction(Top, this->BottomHalf);
		return RetFraction;
	}
	
	int CheckDevisible = 2;
	int LeftBottom = ToAdd.BottomHalf;
	int RightBottom = this->BottomHalf;

	vector<int> LeftPrimes = GetPrimes(LeftBottom);
	vector<int> RightPrimes = GetPrimes(RightBottom);

	int FinalBottom = 1;

	for (int PrimeID = 0; PrimeID < PrimeList.size(); PrimeID++)
	{
		int LeftPrimeCount  = 0;
		int RightPrimeCount = 0;

		for (int LeftPrimeID = 0; LeftPrimeID < LeftPrimes.size(); LeftPrimeID++)
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
		for (int RightPrimeID = 0; RightPrimeID < RightPrimes.size(); RightPrimeID++)
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

	int LTop = (ToAdd.TopHalf * (FinalBottom / LeftBottom));
	int RTop = (this->TopHalf * (FinalBottom / RightBottom));

	int Top = LTop + RTop;
	return Fraction(Top, FinalBottom);
};

Fraction Fraction::SubtractFraction(Fraction ToSubtract)
{
	if (ToSubtract.BottomHalf == this->BottomHalf)
	{
		int Top = ToSubtract.TopHalf - this->TopHalf;
		Fraction RetFraction(Top, this->BottomHalf);
		return RetFraction;
	}
	
	int CheckDevisible = 2;
	int LeftBottom = ToSubtract.BottomHalf;
	int RightBottom = this->BottomHalf;

	vector<int> LeftPrimes = GetPrimes(LeftBottom);
	vector<int> RightPrimes = GetPrimes(RightBottom);

	int FinalBottom = 1;

	for (int PrimeID = 0; PrimeID < PrimeList.size(); PrimeID++)
	{
		int LeftPrimeCount  = 0;
		int RightPrimeCount = 0;

		for (int LeftPrimeID = 0; LeftPrimeID < LeftPrimes.size(); LeftPrimeID++)
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
		for (int RightPrimeID = 0; RightPrimeID < RightPrimes.size(); RightPrimeID++)
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

	int LTop = (ToSubtract.TopHalf * (FinalBottom / LeftBottom));
	int RTop = (this->TopHalf * (FinalBottom / RightBottom));

	int Top = RTop - LTop;
	return Fraction(Top, FinalBottom);
};

Fraction Fraction::MultiplyFraction(Fraction ToMultiply)
{
	int TopHalf = this->TopHalf * ToMultiply.TopHalf;
	int BottomHalf = this->BottomHalf * ToMultiply.BottomHalf;
	
	return Fraction(TopHalf, BottomHalf);
}

Fraction Fraction::DevideFraction(Fraction ToDevide)
{
	int TopHalf    = this->TopHalf * ToDevide.BottomHalf;
	int BottomHalf = this->BottomHalf * ToDevide.TopHalf;
	return Fraction(TopHalf, BottomHalf);
}