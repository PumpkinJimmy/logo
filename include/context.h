#ifndef _LOGO_CONTEXT_H
#define _LOGO_CONTEXT_H
#include "surface.h"
#include "turtle.h"
struct Context
{
	Surface* surface;
	Turtle turtle;
	vector<int> loopcnts;
	vector<int> looppos;
	map<string, int> vars;//table of vars
	map<string, int> funcs;//table of the start lineno of funcs
};
#endif
