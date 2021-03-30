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

	// 스레드 갯수
	int m_iThreadCount;

	// 하드웨어 프로세스 갯수
	int m_iProcessorCount;

	// 계산해야할 숫자
	int m_iTargetNum;

	// 스레드당 계산할 숫자의 갯수
	int m_iOffset;

	// 결과값
	int m_iResult;

	// 공유자원관리용 mutex
	std::mutex m_Mutex;


	// 스레드 함수
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

	// 스레드에 입력한 계산 범위
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

	// 계산 범위 설정	
	int offset = _iCurrOffset + m_iOffset;

	// 남은 계산 범위가 m_iOffset 보다 적으면, 현재 스레드에서 나머지 숫자를 모두 계산
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

	// 스레드가 종료될때까지 기다려야 결과값이 나옴

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