#include "stdafx.h"

int main()
{
	std::list<int> nums;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(0);

	std::list<int>::iterator begin = nums.begin();
	std::list<int>::iterator end = nums.end();

	begin += 100;


	std::cout <<  << std::endl;

	//t1.join();

	return 0;
}