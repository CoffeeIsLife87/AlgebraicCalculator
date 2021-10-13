#include <vector>
#include <iostream>
#pragma once

// Chances are a number isn't going to use a prime over 29. And even 29 is being a bit cautious
const vector<int> PrimeList = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
const int PLSize = (int)PrimeList.size();
namespace Primes {
    vector<int> GetPrimes(int Num);
	int* NumberOfPrimes(vector<int> Num);
};

vector<int> Primes::GetPrimes(int Num)
{
	if (Num == 0)
	{
		vector<int> F;
		return F;
	}
	vector<int> Primes;
	int TmpNum = Num;
	int StartingPrime = 0;
	while (true)
	{
		bool Continue = false;
		// If the number is divisible by the current prime
		if ((TmpNum % PrimeList[StartingPrime]) == 0)
		{
			// Devide
			TmpNum = TmpNum / PrimeList[StartingPrime];

			// output what number it was (debugging)
			//cout << std::to_string(PrimeList[StartingPrime]) << endl;

			// add that number to the list of primes making up the number
			Primes.push_back(PrimeList[StartingPrime]);

			// Since we don't want to return the list yet, we set this value to true
			Continue = true;
		}
		else
		{
			// If the starting prime is still in range, we continue
			if (StartingPrime < PLSize)
			{
				Continue = true;
				StartingPrime += 1;
			}

			// if We've done all we can to the number, now we return it (Meaning we don't set "Continue" to true)
		}

		if (Continue)
		{
			// Don't leave the loop if we're not done yet
			continue;
		}
		else
		{
			return Primes;
		}
	}
}

int* Primes::NumberOfPrimes(vector<int> Num)
{
    int* PrimeCount = new int[PLSize];
    
	int PrimePos = 0;
	int NumPos   = 0;

	while (true)
	{
		if ((PrimePos >= PLSize) || (NumPos >= Num.size()))
		{
			break;
		}

		if (Num[NumPos] == PrimeList[PrimePos])
		{
			PrimeCount[PrimePos] += 1;
			NumPos++;
		}
		else
		{
			PrimePos++;
		}
	}
	return PrimeCount;
}