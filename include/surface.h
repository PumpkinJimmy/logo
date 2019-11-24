#ifndef _LOGO_SURFACE_H
#define _LOGO_SURFACE_H
#include <string>
#include "base.h"

using namespace std;
class Surface
{
public:
	Surface(){width = height = 0;};
	Surface(int _width, int _height, Color _bgcolor){create(_width, _height, _bgcolor);}
	int getWidth() const { return width; };
	int getHeight() const { return height; };
	virtual void create(int _width, int _height, Color _bgcolor)= 0;
	virtual void drawLine(Point st, Point ed, Color color) = 0;
	virtual void save(const string& filename) = 0;
protected:
	int width;
	int height;
};

class DummySurface: public Surface
{
public:
	DummySurface();
	DummySurface(int _width, int _height, Color _bgcolor);
	virtual void create(int _width, int _height, Color _bgcolor);
	virtual void drawLine(Point st, Point ed, Color color);
	virtual void save(const string& filename);
	~DummySurface();
private:
	DummySurface(const DummySurface&);
	DummySurface& operator=(const DummySurface&);
	char** data;
};
#endif
