#include <cstdlib>
#include <cctype>
#include <vector>
#include <string>
#include "interpreter.h"
#include "surface.h"
using namespace std;

Interpreter::Interpreter(Surface* surface)
{
	if (surface == nullptr)
	{
		context.surface = new DummySurface();
	}
	else context.surface = surface;
}
Interpreter::~Interpreter()
{
	delete context.surface;
}
void Interpreter::strip(string& s)
{
	int p = 0;
	while (p < s.size() && isspace(s[p])) p++;
	s.erase(0, p - 0);
	p = s.size() - 1; while (p >= 0 && isspace(s[p])) p--;
	s.erase(p + 1, s.size() - p - 1);
}
void Interpreter::split(string& s, char c, vector<string>& items)
{
	items.clear();
	int lpos = 0, pos = 0;
	while (lpos < s.size() && (pos = s.find(c, lpos)) != string::npos)
	{
		items.push_back(s.substr(lpos, pos - lpos));
		lpos = pos + 1;
	}
	if (lpos < s.size()) items.push_back(s.substr(lpos));
}
void Interpreter::init(int width, int height, Color color, Point pos)
{
	context.turtle = Turtle(pos);
	context.surface->create(width, height, color);
}
void Interpreter::interprete(const string& line)
{
	string l = line;
	strip(l);
	vector<string> items;
	split(l, ' ', items);
	string cmd = items[0]; items.erase(items.begin());
	if (!mp_statement.count(cmd))
		throw "Unknown Command";
	mp_statement[cmd]->execute(context, items);
}
void Interpreter::run(const string& code, const string& filename)
{
	int pos = 0, lpos = 0;
	string codecp = code;
	strip(codecp);
	split(codecp, '\n', lines);
	string line;
	vector<string> items;
	int width, height; Color color; Point p;
	for (int i = 0; i < 3; i++)
	{
		line = lines[0];
		lines.erase(lines.begin());
		split(line, ' ', items);
		if (items[0] == "@SIZE")
		{
			width = atoi(items[1].c_str());
			height = atoi(items[2].c_str());
		}
		else if (items[0] == "@BACKGROUND")
		{
			color.r = atoi(items[1].c_str());
			color.g = atoi(items[2].c_str());
			color.b = atoi(items[3].c_str());
		}
		else if (items[0] == "@POSITION")
		{
			p.x = atoi(items[1].c_str());
			p.y = atoi(items[2].c_str());
		}
		else
		{
			throw "Invalid header";
		}
	}
	init(width, height, color, p);
	for (auto line: lines)
	{
		interprete(line);
	}
	output(filename);
}
void Interpreter::output(const string& filename)
{
	context.surface->save(filename);
}
