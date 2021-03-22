#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

typedef duration<double, milli> doubleMillies;

class CSum
{
public:
	CSum();
	CSum(int calcNum, int threadCount);
	~CSum();

	int GetResult();
	double GetRuntime();

	void SetParam(int calcNum, int threadCount);

	void DoCalculate();

	void PrintResult();

private:
	system_clock::time_point mStartClock, mEndClock;
	doubleMillies mRuntime;

	int mCalcNum;
	int mThreadCount;
	int mCompleteThreadCount;

	int mOffset;
	int mLastOffset;

	int mResult;

	SRWLOCK mSRW;

	vector<thread> mThreadContainer;

	bool calcOffset();
	bool setThread();
	bool runThread();

	void threadFunc(int start, int offset);
};