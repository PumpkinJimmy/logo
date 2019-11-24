#include <iostream>
#include "interpreter.h"
using namespace std;
int main()
{
	Interpreter ipt;
	try
	{
		ipt.run("@SIZE 800 600\n@BACKGROUND 0 0 255\n@POSITION 0 0", "a.bmp");
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	return 0;

}
