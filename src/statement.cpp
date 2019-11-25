#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include "context.h"
#include "statement.h"
using namespace std;

void DefStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 2)
		throw "Invalid usage of DEF";
	if (context.vars.count(items[0]) != 0)
		throw (string("Redefined variable: ") + items[0]).c_str();
	context.vars[items[0]] = atoi(items[1].c_str());
	context.ir += 1;
}

void AddStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 2)
		throw "Invalid usage of ADD";
	if (context.vars.count(items[0]) == 0)
		throw (string("Undefined variable: ") + items[0]).c_str();
	context.vars[items[0]] += atoi(items[1].c_str());
	context.ir += 1;
}

void MoveStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
		throw "Invalid usage of MOVE";
	Point st = context.turtle.getPosition();
	Point ed = context.turtle.move(atoi(items[0].c_str()));
	context.surface->drawLine(st, ed, context.turtle.getColor());
	context.ir += 1;
}
void TurnStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
		throw "Invalid usage of TURN";
	context.turtle.turn(atoi(items[0].c_str()));
	context.ir += 1;
}
void ColorStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 3)
		throw "Invalid usage of COLOR";
	context.turtle.setColor(Color(atoi(items[0].c_str()), atoi(items[0].c_str()), atoi(items[0].c_str())));
	context.ir += 1;
}

	
void CloakStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 0)
		throw "Invalid usage of CLOAK";
	context.turtle.cloak();
	context.ir += 1;
}

