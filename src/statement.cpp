#include <cstdio>
#include <cstdlib>
#include <cctype>
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
	if (isdigit(items[0][0]))
		throw "Invalid variable name";
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

void PrintStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
		throw "Invalid usage of PRINT";
	if (isdigit(items[0][0]))
	{
		printf("%d\n", atoi(items[0].c_str()));
	}
	else
	{
		printf("%d\n", context.vars[items[0]]);
	}
	context.ir++;
}
void LoopStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
	{
		throw "Invalid usage of LOOP";
	}
	int cnt = atoi(items[0].c_str());
	if (cnt <= 0)
	{
		throw "Invalid loop count";
	}
	context.loopcnts.push(cnt);
	context.looppos.push(context.ir + 1);
	context.ir++;
}
void EndStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
	{
		throw "Invalid usage of END";
	}
	if (items[0] == "LOOP")
	{
		if (context.looppos.empty())
		{
			throw "Invalid usage of END LOOP";
		}
		if (context.loopcnts.top() == 1)
		{
			context.loopcnts.pop();
			context.looppos.pop();
			context.ir++;
			return;
		}
		else
		{
			context.loopcnts.top()--;
			context.ir = context.looppos.top();
		}
	}
	else
	{
		throw "Undefined END";
	}
}

