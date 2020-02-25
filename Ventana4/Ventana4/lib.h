#ifndef LIB_H
#define LIB_H
#include <string>
#include <sstream> 
using namespace std;

struct Vector2
{
	float x, y;
};
struct Vector3
{
	float x, y, z;
};
class Lib
{
public:
	static int StringToInt(string str);
};
#endif
