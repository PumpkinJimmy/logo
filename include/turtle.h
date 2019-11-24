#ifndef _LOGO_TURTLE_H
#define _LOGO_TURTLE_H
#include "base.h"
class Turtle
{
public:
	Turtle(Point _pos);
	Point getPosition() const;
	Point move(int dist);
	int getYaw() const;
	void turn(int dyaw);
	Color getColor() const;
	void setColor(Color _color);
	void cloak();
private:
	Point pos;
	int yaw;
	Color color;
	bool is_cloak;
	double toRadius(int deg) { return deg  * PI / 180; }
};

#endif
