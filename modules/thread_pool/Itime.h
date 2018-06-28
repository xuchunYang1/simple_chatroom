#ifndef _ITIME_H
#define _ITIME_H
#include <stdint-gcc.h>

#ifdef __WIN32
#include <windows.h>
#endif // __WIN32

#include <time.h>

#ifdef __WIN32

class ITimer{

private:
    LARGE_INTEGER large_integer;
    int64_t IntStart;
    int64_t IntEnd;
    double DobDff;
    double DobMillseconds;

public:
    ITimer(){};
    void TimerStart();
    double TimerFinish();
    int64_t getCurrent();
};
#else
class ITimer{

public:
	int64_t gettime();// micro-second
};
#endif

#endif // _ITIME_H
