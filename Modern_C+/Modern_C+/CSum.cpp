#include "CSum.h"

thread_local int local_cnt = 0;

CSum::CSum()
	:mCalcNum(0), mThreadCount(0), mResult(0), mOffset(0), mLastOffset(0), mCompleteThreadCount(0)
{
	InitializeSRWLock(&mSRW);
}

CSum::CSum(int calcNum, int threadCount)
	: mCalcNum(calcNum), mThreadCount(threadCount), mResult(0), mOffset(0), mLastOffset(0), mCompleteThreadCount(0)
{
	InitializeSRWLock(&mSRW);
}

CSum::~CSum()
{
}

bool CSum::calcOffset()
{
	if (mCalcNum == 0 || mThreadCount == 0)
	{
		cout << "[ERROR] CSum >> CalcOffset() : parameter is zero, please SetParam()" << endl;
		return false;
	}

	if (mCalcNum < mThreadCount)
	{
		cout << "[ERROR] CSum >> CalcOffset() : thread count > calc num, please retry SetParam()" << endl;
		return false;
	}

	mOffset = (mCalcNum / mThreadCount);
	mLastOffset = mCalcNum % mThreadCount;

	return true;
}

bool CSum::setThread()
{
	int offset = 0;

	if (mOffset <= 0)
	{
		cout << "[ERROR] CSum >> SetThread() : offset is zero, please CalcOffset()" << endl;
		return false;
	}

	for (int i = 0; i < mThreadCount; ++i)
	{
		offset = (i == mThreadCount - 1) ? (mOffset + mLastOffset) : mOffset;

		mThreadContainer.emplace_back(&CSum::threadFunc, this, (mOffset * i) + 1, offset);
	}

	return true;
}

bool CSum::runThread()
{
	if (mThreadContainer.size() == 0)
	{
		cout << "[ERROR] CSum >> SetThread() : thread size is zero, please SetThread()" << endl;
		return false;
	}

	mStartClock = system_clock::now();

	for (int i = 0; i < mThreadContainer.size(); ++i)
	{
		mThreadContainer[i].join();
	}

	return true;
}

void CSum::threadFunc(int start, int offset)
{
	int result = 0;
	int end = start + offset - 1;

	for (; start <= end; ++start)
	{
		result += start;
		++local_cnt;
	}

	cout << local_cnt << endl;

	AcquireSRWLockExclusive(&mSRW);

	mResult += result;
	++mCompleteThreadCount;

	ReleaseSRWLockExclusive(&mSRW);

	if (mCompleteThreadCount == mThreadCount)
	{
		mEndClock = system_clock::now();
		mRuntime = duration_cast<doubleMillies>(mEndClock - mStartClock);
	}
}

void CSum::SetParam(int calcNum, int threadCount)
{
	mCalcNum = calcNum;
	mThreadCount = threadCount;
}

void CSum::DoCalculate()
{
	if (calcOffset() == false)
		return;

	if (setThread() == false)
		return;

	if (runThread() == false)
		return;
}

int CSum::GetResult()
{
	return mResult;
}

double CSum::GetRuntime()
{
	return mRuntime.count();
}

void CSum::PrintResult()
{
	cout << "Sum : " << GetResult() << endl;
	cout << "Runtime : " << GetRuntime() << " ms" << endl;
}