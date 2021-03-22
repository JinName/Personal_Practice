#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base 持失切" << std::endl;
	}

	virtual ~Base()
	{
		std::cout << "Base 社瑚切" << std::endl;
	}
};

class Person : public Base
{
public:
	Person()
	{
		std::cout << "Person 持失切" << std::endl;
	}

	virtual ~Person()
	{
		std::cout << "Person 社瑚切" << std::endl;
	}
};


//int main()
//{
//	Base* base = new Person();
//
//	delete base;
//
//	return 0;
//}