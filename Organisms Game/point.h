#pragma once

class Point
{
public:
	bool operator==(const Point& otherp) {
		return (x == otherp.x && y == otherp.y);
	}
	Point(int x, int y);
	Point();

	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
protected:
	int x;
	int y;
};