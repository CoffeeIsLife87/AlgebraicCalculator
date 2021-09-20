#pragma once
#include <vector>
using namespace std;

enum RAnglePolygonDirection
{
	PolyUp,
	PolyDown,
	PolyLeft,
	PolyRight
};

class RightAngleShape
{
public:
	/*----------------------------------*\
	| A shape made only of right angles  |
	\*----------------------------------*/
	RightAngleShape(vector<double> Length, vector<RAnglePolygonDirection> Turn);

	//double GetArea();
	//double GetPerimeter();

private:
	double Area      = 0;
	double Perimeter = 0;
};
