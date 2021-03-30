#include <iostream>

// ������
void swap(int* _a, int* _b)
{
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}

// ����������
void swap(int** _a, int** _b)
{
	std::cout << _a << std::endl;

	int* temp = *_a;
	*_a = *_b;
	*_b = temp;
}

// ������
void swap(int& _a, int& _b)
{
	int temp = _a;
	_a = _b;
	_b = temp;
}

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;

	int* pA = &a;
	int* pB = &b;

	std::cout << &pA << std::endl;

	swap(&pA, &pB);

	std::cout << a << " / " << b << std::endl;

	return 0;
}