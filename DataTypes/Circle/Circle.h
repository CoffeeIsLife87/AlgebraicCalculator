#pragma once
#define pi 3.14

class Circle
{
	/*---------------------------------------------------------*\
	| A circle													|
	|															|
	| Calculates almost all aspects of it during contruction	|
	\*---------------------------------------------------------*/
public:
	Circle(int Radius, bool FromRadius );

	double GetRadius();
	double GetDiameter();
	double GetCircumfrence();
	double GetArea();

private:
	double Circumfrence;
	double Diameter;
	double Radius;
	double Area;
};
