#pragma once
#include <Windows.h>


//
// Based on code from Dr. Fawcett:
// http://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer.cpp	 
// http ://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer.

class CWindowsStopWatch
{
public:
	CWindowsStopWatch();
	~CWindowsStopWatch();
	void start();
	void stop();
	long getTime();

protected:
	__int64 a, b, f;
};

