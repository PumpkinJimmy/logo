#ifndef _LOGO_EXCEPTION_H
#define _LOGO_EXCEPTION_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class LogoError
{
public:
	LogoError(const string& _msg): msg(_msg) {}
	virtual void showMsg() const { cout << msg << endl;}
protected:
	string msg;
};
class LogoRuntimeError: public LogoError
{
public:
	LogoRuntimeError(const string& _msg, int ir): LogoError(_msg), error_ir(ir) {}
	virtual void showMsg() const {
		cout << "LogoRuntimeError: Line" << error_ir << ": "  << msg << endl;
	}

protected:
	int error_ir;
};

class LogoUndefinedVariable: public LogoError
{
public:
	LogoUndefinedVariable(int ir, const string& name): LogoRuntimeError("Undefined Variable", ir), var_name(name){}
	virtual void showMsg() const {
		cout << "LogoUndefinedVariable: Line" << error_ir << ": " << var_name << endl;
protected:
	string var_name;
	}
};
class LogoInvalidUsage: public LogoError
{
public:
	LogoInvalidUsage(int ir): LogoRuntimeError("Invalid Usage", ir) {}
	virtual void showMsg() const {
		cout << "LogoInvalidUsage: Line" << error_ir << endl;
	}
};
class LogoInvalidLoopCount: public LogoError
{
public:
	LogoInvalidLoopCount(int ir, const string& lc): LogoRuntimeError("Invalid loop count", ir), lc_string(lc) {}
	virtual void showMsg() const {
		cout << "LogoInvalidLoopCount: Line" << error_ir << ": " << lc_string << endl;
	}
protected:
	string lc_string;

};
#endif
