#include <iostream>

class Man
{
	class Head
	{
	public:
		Head() { std::cout << "Head" << std::endl; }

		virtual ~Head() { std::cout << "~Head" << std::endl; }
	};

	class Tail
	{
	public:
		Tail() { std::cout << "Tail" << std::endl; }

		virtual ~Tail() { std::cout << "~Tail" << std::endl; }
	};

	Head head;
	Tail tail;

public:
	Man() { std::cout << "Man" << std::endl; }

	virtual ~Man() { std::cout << "~Man" << std::endl; }
};

int main()
{
	Man man;

	return 0;
}

//Head
//Tail
//Man
//~Man
//~Tail
//~Head