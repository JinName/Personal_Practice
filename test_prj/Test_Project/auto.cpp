
#include <iostream>

int main(int argc, char* argv[])
{
	int num = 10;
	int num2 = 20;
	auto f1 = [](int _a, int _b) {
		++_a;
		++_b;

		return _a + _b;
	};

	auto f2 = [](int& _a, int& _b) {
		++_a;
		++_b;

		return _a + _b;
	}(num, num2); // 명백한 호출로 전달된 매개변수는 const 로 취급하여, 새로운 매개변수 또는 매개변수로 전달된 값이 변경되어도 적용되지않는다.

	num = 15;
	num2 = 25;

	std::cout << f1(10, 2) << std::endl;
	std::cout << f2 << std::endl;

	return 0;
}