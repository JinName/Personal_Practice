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
	// ������ ����
	size_t m_Thread_Count;

	// ������ ����
	bool m_bStop_All;

	// ������ Ǯ
	std::vector<std::thread> m_Thread_Pool;

	// ������ wakeup ����
	std::condition_variable m_cv;

	// �������̵� �ؾ��ϴ� worker thread
	virtual void workerThread() = 0;
};

