#include "Itime.h"

#ifdef __WIN32
void ITimer::TimerStart()
{
    QueryPerformanceFrequency(&large_integer);
    DobDff = large_integer.QuadPart;

    QueryPerformanceCounter(&large_integer);
    IntStart = large_integer.QuadPart;
}
double ITimer::TimerFinish()
{
    QueryPerformanceCounter(&large_integer);
    IntEnd = large_integer.QuadPart;
    DobMillseconds = (IntEnd - IntStart) * 1000 / DobDff; //return ms
    return DobMillseconds;
}
int64_t ITimer::getCurrent()
{
    QueryPerformanceFrequency(&large_integer);
    DobDff = large_integer.QuadPart;

    QueryPerformanceCounter(&large_integer);
    return large_integer.QuadPart;
}
#else
int64_t ITimer::gettime()
{
	struct timespec tv;
	clock_gettime(CLOCK_MONOTONIC, &tv);
	return (int64_t)(tv.tv_sec* 1000000 + tv.tv_nsec/1000);
}
#endif
