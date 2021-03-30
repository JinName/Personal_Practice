// 다음에서 잘못된 부분을 수정하시오.

class CTest
{
	const int num;

	CTest(int _num) { num = _num; }
	~CTest() {}
};

// 정답
// CTest(int _num) : num(_num) {}

// const 키워드가 붙은 멤버 변수는 생성자의 : 를 통해 생성시 초기화해야한다.