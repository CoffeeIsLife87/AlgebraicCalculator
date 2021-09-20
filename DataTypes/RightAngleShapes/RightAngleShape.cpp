#include "RightAngleShape.h"

RightAngleShape::RightAngleShape(vector<double> Length, vector<RAnglePolygonDirection> Turn)
{
	if (Length.size() != Turn.size()) return;
	int CurrentPos[2] = { 0, 0 };
	for (int Side = 0; Side < (int)Length.size(); Side++)
	{
		switch (Turn[Side])
		{
		case PolyDown:
			CurrentPos[1] -= Length[Side];
			Perimeter += Length[Side];
			break;
		case PolyUp:
			CurrentPos[1] += Length[Side];
			Perimeter += Length[Side];
			break;
		case PolyLeft:
			CurrentPos[0] -= Length[Side];
			Perimeter += Length[Side];
			break;
		case PolyRight:
			CurrentPos[0] += Length[Side];
			Perimeter += Length[Side];
			break;
		default:
			break;
		}
	}
	
	if (!(CurrentPos[0] == 0) || !(CurrentPos[1] == 0)) return;

}
