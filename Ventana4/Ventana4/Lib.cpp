#include "lib.h"

int Lib::StringToInt(string str)
{
	int x = 0;
	stringstream geek(str);
	geek >> x;
	return x;
}