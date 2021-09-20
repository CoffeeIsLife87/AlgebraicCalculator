#include "FixedDistanceUniformMotion.h"
#include <iostream>
/*-----------------------------------------------------------------------------------------------------*\
| There are multiple structures for this kind of problem												|
|																										|
| If statement #1 handles when the time of both is defined and the rate for 1 is greater than the other |
| If statement #2 handles when the rate of both is defined and the time for 1 is greater than the other |
\*-----------------------------------------------------------------------------------------------------*/

void FixedDistanceUniformMotion::FindDistance()
{
	if      ((TX > -1) && (TY > -1) && (XRateFaster  > 0) && (RX == -1 && RY == -1 && Distance == -1))
	{
		int TempRX = TX * XRateFaster;
		int TempOther = TX - TY;

		if (TempOther < 0)
		{
			TempOther *= -1;
		}
		if (TempRX < 0)
		{
			TempRX *= -1;
		}

		RY = TempRX / TempOther;
		RX = RY + XRateFaster;
		
		Distance = RX * TX;

		std::cout << "Rate 1 = " << RX << "\nRate 2 = " << RY << "\nDistance = " << Distance;
	}
	else if ((RX > -1) && (RY > -1) && (XTimeGreater > 0) && (TX == -1 && TY == -1 && Distance == -1))
	{
		int TempTX        = RX * XTimeGreater;
		int RightSideTemp = RY - RX;

		if (TempTX < 0) // Make sure it isn't negative
		{
			TempTX *= -1;
		}
		if (RightSideTemp < 0) // Same as above opperation
		{
			RightSideTemp *= -1;
		}

		TY = TempTX / RightSideTemp; // Find the second variable time it took
		TX = TY     + XTimeGreater;  // Find the first variable time it took

		Distance = RX * TX;

		std::cout << "Variable 1 time = " << TX << "\nVariable 2 time = " << TY << "\nDistance = " << Distance;
	}
}