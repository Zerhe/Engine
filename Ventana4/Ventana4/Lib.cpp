#include "lib.h"

int Lib::StringToInt(string str)
{
	int x = 0;
	stringstream geek(str);
	geek >> x;
	return x;
}
float Lib::CalculateDistance(Vector3 targetPosition, Vector3 startPosition)
{
	static Vector3 heading;
	static float distance;

	heading.x = targetPosition.x - startPosition.x;
	heading.y = targetPosition.y - startPosition.y;
	heading.z = targetPosition.z - startPosition.z;

	distance = heading.Magnitude();
	return distance;

}