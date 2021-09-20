#pragma once
class ExponentialInt
{
public:
	ExponentialInt(char Base, int Exponent, char coeffecient = '1');

	const bool IsNonNumber;
	const char Base;
	const int  Exponent;
	
	const char Coeffecient;
	const bool HasCoefficient;
	const bool IsNonNumberCoeffecient;

	int GetMultiplied();

private:
	int Multiplied = 0;

};
