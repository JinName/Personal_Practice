#include "ThreadPoolBase.h"

ThreadPoolBase::ThreadPoolBase(size_t _thread_cnt)
	:m_Thread_Count(_thread_cnt), m_bStop_All(false)
{
	m_Thread_Pool.reserve(m_Thread_Count);
	for (int i = 0; i < m_Thread_Count; ++i)
	{
		m_Thread_Pool.emplace_back([this]() {this->workerThread(); });
	}
}

ThreadPoolBase::~ThreadPoolBase()
{
	m_bStop_All = true;
	m_cv.notify_all(); // 모든 스레드 깨움

	for (auto& thread : m_Thread_Pool)
	{
		thread.join();
	}
}