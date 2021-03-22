#include <iostream>

void swap(int* _a, int* _b)
{
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}

void swap(int& _a, int& _b)
{
	int temp = _a;
	_a = _b;
	_b = temp;
}


//int main()
//{
//	int* a = new int(10);
//	int* b = new int(20);
//
//	swap(a, b);
//
//	std::cout << *a << " / " << *b << std::endl;
//
//	return 0;
//}