#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class SumThreads
{
public:
	SumThreads(int _iThreadCount, int _iTargetNum);
	~SumThreads();

	void CreateThreads();

	void JoinThreads();

	int GetResult() { return m_iResult; }
	int GetProcessorCnt() { return m_iProcessorCount; }
private:
	std::vector<std::thread> m_ThreadContainer;

	// ������ ����
	int m_iThreadCount;

	// �ϵ���� ���μ��� ����
	int m_iProcessorCount;

	// ����ؾ��� ����
	int m_iTargetNum;

	// ������� ����� ������ ����
	int m_iOffset;

	// �����
	int m_iResult;

	// �����ڿ������� mutex
	std::mutex m_Mutex;


	// ������ �Լ�
	void workerThread(int _iCurrOffset);
};

SumThreads::SumThreads(int _iThreadCount, int _iTargetNum)
	: m_iThreadCount(_iThreadCount), m_iTargetNum(_iTargetNum), m_iProcessorCount(std::thread::hardware_concurrency()), m_iOffset(0), m_iResult(0)
{

	m_iOffset = m_iTargetNum / m_iThreadCount;
}

SumThreads::~SumThreads()
{

}

void SumThreads::CreateThreads()
{
	m_ThreadContainer.resize(m_iThreadCount);

	// �����忡 �Է��� ��� ����
	int total_offset = 0;

	for (auto& t : m_ThreadContainer)
	{
		t = std::thread([this](int _total_offset) { this->workerThread(_total_offset); }, total_offset);

		total_offset += m_iOffset;
	}
}

void SumThreads::JoinThreads()
{
	for (auto& t : m_ThreadContainer)
	{
		t.join();
	}
}

void SumThreads::workerThread(int _iCurrOffset)
{
	int sum = 0;

	// ��� ���� ����	
	int offset = _iCurrOffset + m_iOffset;

	// ���� ��� ������ m_iOffset ���� ������, ���� �����忡�� ������ ���ڸ� ��� ���
	if (m_iOffset > m_iTargetNum - offset)
	{
		offset += m_iTargetNum - offset;
	}

	for (int i = _iCurrOffset + 1; i <= offset; ++i)
	{
		sum += i;
	}

	// lock, unlock
	m_Mutex.lock();

	m_iResult += sum;

	m_Mutex.unlock();
}


int main(int argc, char* argv[])
{
	SumThreads threads(15, 231);
	threads.CreateThreads();
	threads.JoinThreads();

	// �����尡 ����ɶ����� ��ٷ��� ������� ����

	std::cout << threads.GetResult() << std::endl;
	std::cout << threads.GetProcessorCnt() << std::endl;
	std::cout << std::this_thread::get_id() << std::endl;

	int res = 0;

	for (int i = 1; i <= 231; ++i)
	{
		res += i;
	}

	std::cout << res << std::endl;	

	return 0;
}