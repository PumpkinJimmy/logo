#ifndef _LOGO_INTERPRETER_H
#define _LOGO_INTERPRETER_H
#include <string>
#include "base.h"
#include "surface.h"
#include "turtle.h"
using namespace std;
struct Context
{
	Surface surface;
	Turtle turtle;
};
class Interpreter
{
public:
	Interpreter();
	int interprete(const string& line);
};

#endif
