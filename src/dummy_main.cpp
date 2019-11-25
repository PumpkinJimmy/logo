#include <iostream>
#include <fstream>
#include "interpreter.h"
#include "statement.h"
using namespace std;
int main(int argc, char** argv)
{
	Interpreter ipt;
	ipt.addStatement("DEF", new DefStatement);
	ipt.addStatement("ADD", new AddStatement);
	ipt.addStatement("MOVE", new MoveStatement);
	ipt.addStatement("TURN", new TurnStatement);
	ipt.addStatement("COLOR", new ColorStatement);
	ipt.addStatement("CLOAK", new CloakStatement);
	try
	{
		if (argc < 2) throw "No source code filename provided";
		//ipt.run("@SIZE 800 600\n@BACKGROUND 0 0 255\n@POSITION 0 0\nDEF a 1\nDEF b 2\nADD a 1\nADD b -3", "a.bmp");
		ipt.runFromFile(argv[1], "a.bmp");

	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	return 0;

}
