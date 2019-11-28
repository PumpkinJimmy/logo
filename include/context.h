#ifndef _LOGO_CONTEXT_H
#define _LOGO_CONTEXT_H
#include <map>
#include <string>
#include <stack>
#include "surface.h"
#include "turtle.h"
using namespace std;
struct Context
{
	Surface* surface;
	Turtle turtle;
	stack<int> loopcnts;
	stack<int> looppos;
	stack<int> callpos;
	map<string, int> vars;//table of vars
	map<string, int> funcs;//table of the start lineno of funcs
	map<string, vector<string>> args;
	int ir;
	bool in_func_def;
};
#endif
