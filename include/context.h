#ifndef _LOGO_CONTEXT_H
#define _LOGO_CONTEXT_H
#include <map>
#include <string>
#include "surface.h"
#include "turtle.h"
using namespace std;
struct Context
{
	Surface* surface;
	Turtle turtle;
	vector<int> loopcnts;
	vector<int> looppos;
	map<string, int> vars;//table of vars
	map<string, int> funcs;//table of the start lineno of funcs
	int ir;
	bool in_func_def;
};
#endif
