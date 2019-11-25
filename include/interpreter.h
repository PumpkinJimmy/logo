#ifndef _LOGO_INTERPRETER_H
#define _LOGO_INTERPRETER_H
#include <string>
#include <vector>
#include <map>
#include "base.h"
#include "context.h"
#include "statement.h"
using namespace std;
class Interpreter
{
public:
	Interpreter(Surface* surface=nullptr);
	~Interpreter();
	void run(const string& filename);
	void run(const vector<string>& lines, const string& filename);
	void run(const string& code, const string& filename);
	void runFromFile(const string& code_file, const string& filename);
	void addStatement(const string& text, Statement* statement);
private:
	Interpreter(const Interpreter&);
	void operator=(const Interpreter&);
	void init(int width, int height, Color bgcolor, Point pos);
	void interprete(const string& line);
	void strip(string& s);
	void split(string& s, char c, vector<string>& items);
	void output(const string& filename);
	void jumpTo(int l);
	vector<string> lines;
	Context context;
	map<string, Statement*> mp_statement; 
};

#endif
