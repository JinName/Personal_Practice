
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
	}(num, num2); // ����� ȣ��� ���޵� �Ű������� const �� ����Ͽ�, ���ο� �Ű����� �Ǵ� �Ű������� ���޵� ���� ����Ǿ ��������ʴ´�.

	num = 15;
	num2 = 25;

	std::cout << f1(10, 2) << std::endl;
	std::cout << f2 << std::endl;

	return 0;
}