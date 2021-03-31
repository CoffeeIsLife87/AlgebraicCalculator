#include "Circle.h"

Circle::Circle(int Number, bool FromRadius)
{
	if (FromRadius)
	{
		this->Radius = Number;
		this->Diameter = Number * 2;
		this->Area = pi * (Number * Number);
		this->Circumfrence = Diameter * pi;
	}
	else
	{
		this->Radius = Number / 2;
		this->Diameter = Number;
		this->Area = pi * (Radius * Radius);
		this->Circumfrence = Number * pi;
	}
}

double Circle::GetCircumfrence()
{
	return Circumfrence;
}
double Circle::GetDiameter()
{
	return Diameter;
}
double Circle::GetRadius()
{
	return Radius;
}
double Circle::GetArea()
{
	return Area;
}