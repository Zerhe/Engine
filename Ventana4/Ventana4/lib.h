#ifndef LIB_H
#define LIB_H
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

struct Vector2
{
	float x, y;
};
struct Vector3
{
	float x, y, z;
	float Magnitude()
	{
		return sqrt(x*x+y*y+z*z);
	}
};
class Lib
{
public:
	static int StringToInt(string str);
	static float CalculateDistance(Vector3 targetPosition, Vector3 startPosition);
};
#endif
