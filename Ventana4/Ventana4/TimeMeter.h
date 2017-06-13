#ifndef TIMEMETER_H
#define TIMEMETER_H
#include "Api.h"
#include <windows.h>
#include <string>
using namespace std;

class VENTANA4_API TimeMeter{
	LARGE_INTEGER _performanceCounter1;
	LARGE_INTEGER _performanceCounter2;
	LARGE_INTEGER _performanceFrequency;
	double _deltaTime;
public:
	void FirstMeasure();
	void Measure();
	double GetDT();
};
#endif
