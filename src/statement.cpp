#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include <utility>
#include "context.h"
#include "statement.h"
using namespace std;
void split(const string& s, char c, vector<string>& items);


void DefStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 2)
		throw "Invalid usage of DEF";
	if (context.vars.count(items[0]) != 0)
		throw (string("Redefined variable: ") + items[0]).c_str();
	if (isdigit(items[0][0]) || items[0].find(',') != string::npos)
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
	else if (items[0] == "FUNC")
	{
		if (context.in_func_def)
		{
			context.in_func_def = false;
			context.ir++;
			return;
		}
		if (context.callpos.empty())
			throw "Invalid usage of END FUNC";
		context.ir = context.callpos.top() + 1; context.callpos.pop();
	}
	else
	{
		throw "Undefined END";
	}
}

void FuncStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
		throw "Invalid usage of FUNC";
	int lpos = items[0].find('(');
	if (lpos == string::npos)
		throw "Invalid usage of FUNC";
	string func_name = items[0].substr(0, lpos);
	if (context.funcs.count(func_name))
		throw "Redefined funtion";
	vector<string> args;
	split(items[0].substr(lpos + 1, items[0].size() - lpos - 2), ',', args);
	context.funcs[func_name] = context.ir;
	context.args[func_name] = args;
	context.in_func_def = true;
	context.ir++;
}
void CallStatement::execute(Context& context, const vector<string>& items)
{
	if (items.size() != 1)
		throw "Invalid usage of CALL";
	int lpos = items[0].find('(');
	if (lpos == string::npos)
		throw "Invalid usage of FUNC";
	string func_name = items[0].substr(0, lpos);
	if (context.funcs.count(func_name) == 0)
		throw "Unknown function call";
	vector<string> args;
	string arg_line = items[0].substr(lpos + 1, items[0].size() - lpos - 2);
	split(arg_line, ',', args);
	if (args.size() != context.args[func_name].size())
		throw "Function arguments count error";
	for (int i = 0; i < args.size(); i++)
	{
		if (isdigit(args[i][0]))
		{
			context.vars[context.args[func_name][i]] = atoi(args[i].c_str());
		}
		else
		{
			if (context.vars.count(args[i]) == 0)
				throw "Undefined variable";
			context.vars[context.args[func_name][i]] = context.vars[args[i]];
		}
	}
	context.callpos.push(context.ir);
	context.ir = context.funcs[items[0]] + 1;
}
