#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base ������" << std::endl;
	}

	virtual ~Base()
	{
		std::cout << "Base �Ҹ���" << std::endl;
	}
};

class Person : public Base
{
public:
	Person()
	{
		std::cout << "Person ������" << std::endl;
	}

	virtual ~Person()
	{
		std::cout << "Person �Ҹ���" << std::endl;
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