#include "TimeMeter.h"

void TimeMeter::FirstMeasure()
{
	QueryPerformanceCounter(&_performanceCounter1);
	QueryPerformanceFrequency(&_performanceFrequency);
}
void TimeMeter::Measure()
{
	QueryPerformanceCounter(&_performanceCounter2);
	_deltaTime = (_performanceCounter2.QuadPart - _performanceCounter1.QuadPart) / (double)_performanceFrequency.QuadPart;
	_performanceCounter1 = _performanceCounter2;
}
double TimeMeter::GetDT()
{
	return _deltaTime;
}