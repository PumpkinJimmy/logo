#ifndef _LOGO_BASE_H
#define _LOGO_BASE_H
#define PI 3.141592653589
struct Color
{
	int r, g, b;
	Color(int _r=0, int _g=0, int _b=0): r(_r), g(_g), b(_b) {}
};
struct Point
{
	int x, y;
	Point(int _x=0, int _y=0):x(_x), y(_y) {}
};

#endif
