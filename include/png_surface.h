#ifndef _LOGO_PNGSURFACE_H
#define _LOGO_PNGSURFACE_H
#include <string>
#include "base.h"

using namespace std;
class PngSurface: public Surface
{
public:
	PngSurface();
	PngSurface(int _width, int _height, Color _bgcolor);
	virtual void create(int _width, int _height, Color _bgcolor);
	virtual void drawLine(Point st, Point ed, Color color);
	virtual void save(const string& filename);
	~PngSurface();
private:
	PngSurface(const PngSurface&);
	PngSurface& operator=(const PngSurface&);
	char** data;
};
#endif
