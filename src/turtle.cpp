#include <cmath>
#include "base.h"
#include "turtle.h"
using namespace std;

Turtle::Turtle()
{
	yaw = 0;
	color = Color(0, 0, 0);
	is_cloak = false;
}
Turtle::Turtle(Point _pos)
{
	pos = _pos;
	yaw = 0;
	color = Color(0, 0, 0);
	is_cloak = false;
}

Point Turtle::getPosition() const
{
	return pos;
}

Point Turtle::move(int dist)
{
	int dx = dist * cos(toRadius(yaw)), dy = dist * sin(toRadius(yaw));
	pos = Point(pos.x + dx, pos.y + dy);
	return pos;
}

int Turtle::getYaw() const
{
	return yaw;
}

void Turtle::turn(int dyaw)
{
	yaw = (yaw + dyaw) % 360;
}

Color Turtle::getColor() const
{
	return color;
}
void Turtle::setColor(Color _color)
{
	color = _color;
	is_cloak = false;
}

bool Turtle::isCloak() const
{
	return is_cloak;
}
void Turtle::cloak()
{
	is_cloak = true;
}
