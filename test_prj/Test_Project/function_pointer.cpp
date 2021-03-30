// �Լ���ü / �Լ������� ����

#include <iostream>
#include <functional>

// �Լ� ��ü
// returntype operator() (parameters) ������ ���� ��ü�� �Լ�ó�� �� �� �ְ� �����.
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
	// �Լ� ��ü
	Plus plus;
	
	std::cout << plus(10, 20) << std::endl;

	// �Լ� ������
	// �������� ���
	int (*fptr)(int) = foo;

	// std::function < ��ȯŸ��(param1, 2...) > ������
	std::function<int(int)> fptr2 = foo;

	std::cout << fptr(5) << std::endl;
	std::cout << fptr2(10) << std::endl;

	return 0;
}