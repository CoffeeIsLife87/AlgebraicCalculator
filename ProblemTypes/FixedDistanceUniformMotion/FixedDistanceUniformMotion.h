#pragma once

/*----------------------------------------------------------------------*\
| This class handles uniform motion problems with fixed/equal distances  |
\*----------------------------------------------------------------------*/
class FixedDistanceUniformMotion
{
public:
	int Distance = -1; // Global distance

	int XRateFaster  = 0;  // For if 1 side RATE (unit/hr) is faster than the other
	int XTimeGreater = 0; // For if 1 side goes SLOWER (Time taken) than another

	int RX = -1; // Rate for variable 1
	int TX = -1; // Time for variable 1

	int RY = -1; // Rate for variable 2
	int TY = -1; // Time for variable 2
		
	void FindDistance(); // Called once variables are filled in.\n Prints the result on its own
};
