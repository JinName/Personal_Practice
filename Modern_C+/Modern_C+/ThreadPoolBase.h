#pragma once
#include <thread>
#include <vector>
#include <condition_variable>
#include <mutex>

class ThreadPoolBase
{
public:
	ThreadPoolBase(size_t _thread_cnt);
	virtual ~ThreadPoolBase();


protected:
	// 스레드 갯수
	size_t m_Thread_Count;

	// 스레드 중지
	bool m_bStop_All;

	// 스레드 풀
	std::vector<std::thread> m_Thread_Pool;

	// 스레드 wakeup 변수
	std::condition_variable m_cv;

	// 오버라이딩 해야하는 worker thread
	virtual void workerThread() = 0;
};

