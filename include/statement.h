#ifndef _LOGO_STATEMENT_H
#define _LOGO_STATEMENT_H
#include <string>
#include "context.h"
using namespace std;
class Statement
{
public:
	Statement(){}
	virtual void execute(Context& context, const vector<string>& items) = 0;
	virtual ~Statement(){}
};
class DefStatement: public Statement
{
public:
	DefStatement(){}
	virtual void execute(Context& context, const vector<string>& items) override;
	virtual ~DefStatement(){}
};

class AddStatement: public Statement
{
public:
	AddStatement(){}
	virtual void execute(Context& context, const vector<string>& items) override;
	virtual ~AddStatement(){}
};

class MoveStatement: public Statement
{
public:
	MoveStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};

class TurnStatement: public Statement
{
public:
	TurnStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class ColorStatement: public Statement
{
public:
	ColorStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class CloakStatement: public Statement
{
public:
	CloakStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class PrintStatement: public Statement
{
public:
	PrintStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class LoopStatement: public Statement
{
public:
	LoopStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class FuncStatement: public Statement
{
public:
	FuncStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class CallStatement: public Statement
{
public:
	CallStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
class EndStatement: public Statement
{
public:
	EndStatement(){}
	virtual void execute(Context& context, const vector<string>& items);
};
#endif
