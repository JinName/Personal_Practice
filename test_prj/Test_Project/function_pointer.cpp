// 함수객체 / 함수포인터 사용법

#include <iostream>
#include <functional>

// 함수 객체
// returntype operator() (parameters) 형식을 통해 객체를 함수처럼 쓸 수 있게 만든다.
class Plus
{
public:
	int operator() (int _a, int _b) { return _a + _b; }
};

int foo(int _a)
{
	return _a;
}

int main()
{
	// 함수 객체
	Plus plus;
	
	std::cout << plus(10, 20) << std::endl;

	// 함수 포인터
	// 원시적인 방법
	int (*fptr)(int) = foo;

	// std::function < 반환타입(param1, 2...) > 변수명
	std::function<int(int)> fptr2 = foo;

	std::cout << fptr(5) << std::endl;
	std::cout << fptr2(10) << std::endl;

	return 0;
}