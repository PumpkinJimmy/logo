#ifndef _LOGO_STATEMENT_H
#define _LOGO_STATEMENT_H
#include <string>
#include "context.h"
using namespace std;
class Statement
{
public:
	Statement();
	virtual void execute(Context& context, const vector<string>& items) = 0;
};
class DefStatement: public Statement
{
public:
	DefStatement();
	virtual void execute(Context& context, const vector<string>& items);
};

class AddStatement: public Statement
{
public:
	AddStatement();
	virtual void execute(Context& context, const vector<string>& items);
};

class MoveStatement: public Statement
{
public:
	MoveStatement();
	virtual void execute(Context& context, const vector<string>& items);
};

class TurnStatement: public Statement
{
public:
	TurnStatement();
	virtual void execute(Context& context, const vector<string>& items);
};
#endif
class ColorStatement: public Statement
{
public:
	ColorStatement();
	virtual void execute(Context& context, const vector<string>& items);
};
class CloakStatement: public Statement
{
public:
	CloakStatement();
	virtual void execute(Context& context, const vector<string>& items);
};
