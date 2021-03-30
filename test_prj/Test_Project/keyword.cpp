
#include <iostream>

int main()
{
	int* __restrict pA = new int(5);

	std::cout << *pA << std::endl;

	delete pA;

	return 0;
}
