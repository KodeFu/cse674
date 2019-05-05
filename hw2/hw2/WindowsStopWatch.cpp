#include "stdafx.h"
#include "WindowsStopWatch.h"


CWindowsStopWatch::CWindowsStopWatch()
{
	b = 0UL;
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&f) == 0)
		throw std::exception("no high resolution counter on this platform");
	QueryPerformanceCounter((LARGE_INTEGER*)&a);
}

CWindowsStopWatch::~CWindowsStopWatch()
{
}

void CWindowsStopWatch::start() {
	::Sleep(0);
	QueryPerformanceCounter((LARGE_INTEGER*)&a);
}

void CWindowsStopWatch::stop() {
	QueryPerformanceCounter((LARGE_INTEGER*)&b);
}

long CWindowsStopWatch::getTime() {
	__int64 d = (b - a);
	__int64 ret_milliseconds;
	ret_milliseconds = (d * 1000UL) / f;
	return (long) ret_milliseconds;
}