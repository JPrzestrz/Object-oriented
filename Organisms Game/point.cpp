#include "point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	x = 0;
	y = 0;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

int Point::GetX()
{
	return x;
}

int Point::GetY()
{
	return y;
}
