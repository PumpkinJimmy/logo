#ifndef _LOGO_SURFACE_H
#define _LOGO_SURFACE_H
#include "base.h"
class Surface
{
public:
	Surface(int _width, int _height, Color _bgcolor);
	int getWidth() const;
	int getHeight() const;
	void drawLine(Point st, Point ed, Color color);
	void save(const string& filename);

};
#endif
