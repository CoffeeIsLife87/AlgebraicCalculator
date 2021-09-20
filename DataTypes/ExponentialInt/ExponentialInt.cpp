#include "ExponentialInt.h"
#include <ctype.h>

ExponentialInt::ExponentialInt(char B, int E, char coeffecient) :
	Base(B), Exponent(E),
	IsNonNumber(!isdigit(B)),
	HasCoefficient((coeffecient == '1' ? false : true)),
	Coeffecient(coeffecient),
	IsNonNumberCoeffecient(!isdigit(coeffecient))
{
	int Final = Base;
	if (Exponent > 0)
	{
		for (int Pass = 0; Pass < Exponent; Pass++)
		{
			Final *= Base;
		}
	}
	else if(Exponent < 0)
	{
		for (int Pass = 0; Pass > Exponent; Pass--)
		{
			Final *= Base;
		}
	}
	else if (Exponent == 0)
	{
		Final = 1;
	}

	Multiplied == Final;
}

int ExponentialInt::GetMultiplied()
{
	if (!IsNonNumber)
	{
		return Multiplied;
	}
	else
	{
		return 0;
	}
}
